#ifndef CBORDERSH
#define CBORDERSH

#include <set>

class CBorders;
typedef CBorders TBorders;

#include "cstring.h"
#include "cborderline.h"
#include "cborderobject.h"
typedef std::set<TBorderObject> TBordersContainer;

class ITBordersFromTStyleSheet
{
public:
virtual TString save() const = 0;
};

class ITBordersFromTBorder
{
public:
virtual void erase(TBordersContainer::iterator& border) = 0;
virtual TBordersContainer::const_iterator begin() const = 0;
};

#include "cborder.h"

class CBorders:
    public ITBordersFromTStyleSheet,
    public ITBordersFromTBorder,
    protected TBordersContainer
{
protected:
typedef TBordersContainer base;

TBorder m_default;

/* ITBordersFromTStyleSheet */
TString save() const;

/* ITBordersFromTBorder */
void    erase(TBordersContainer::iterator& border);
TBordersContainer::const_iterator begin() const;

public:
        CBorders();
TBorder insert();
TBorder insert(
    const TBorderLine& left,
    const TBorderLine& right,
    const TBorderLine& top,
    const TBorderLine& bottom,
    const TBorderLine& diagonal,
    bool down,
    bool up,
    bool outline);
};

#endif

