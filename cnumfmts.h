#ifndef CNUMFMTSH
#define CNUMFMTSH

#include <set>

class CNumFmts;
typedef CNumFmts TNumFmts;

#include "cnumfmtobject.h"
typedef std::set<TNumFmtObject> TNumFmtsContainer;

class ITNumFmtsFromTStyleSheet
{
public:
virtual TString save() const = 0;
};

class ITNumFmtsFromTNumFmt
{
public:
virtual void erase(const TNumFmtsContainer::iterator& it) = 0;
virtual TNumFmtsContainer::const_iterator begin() const = 0;
};

#include "cnumfmt.h"

class CNumFmts:
    public ITNumFmtsFromTStyleSheet,
    public ITNumFmtsFromTNumFmt,
    protected TNumFmtsContainer
{
protected:
typedef TNumFmtsContainer base;

TString save() const;
void    erase(const base::iterator& it);
base::const_iterator begin() const;

public:
        CNumFmts();
TNumFmt insert(ENUMFMT fmt);
TNumFmt insert(const TString& fmt);
};

#endif

