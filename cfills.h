#ifndef CFILLSH
#define CFILLSH

#include <set>

class CFills;
typedef CFills TFills;

#include "cstring.h"
#include "cfillobject.h"
typedef std::set<TFillObject> TFillsContainer;

class ITFillsFromTStyleSheet
{
public:
virtual TString save() const = 0;
};

class ITFillsFromTFill
{
public:
virtual void erase(TFillsContainer::iterator& fill) = 0;
virtual TFillsContainer::const_iterator begin() const = 0;
};

#include "cfill.h"

class CFills:
    public ITFillsFromTStyleSheet,
    public ITFillsFromTFill,
    protected TFillsContainer
{
protected:
typedef TFillsContainer base;

TFill   m_default0;
TFill   m_default1;

template <class T>
TFill   base_insert(const T& fill);

/* ITFillsFromTStyleSheet */
TString save() const;

/* ITFillsFromTFill */
void    erase(base::iterator& fill);
base::const_iterator begin() const;

public:
        CFills();
TFill   insert();
TFill   insert(const TGradientFill& fill);
TFill   insert(const TPatternFill& fill);
};

#endif

