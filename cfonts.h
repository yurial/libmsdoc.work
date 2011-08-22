#ifndef CFONTSH
#define CFONTSH

#include <set>

class CFonts;
typedef CFonts TFonts;

#include "cfontobject.h"
typedef std::set<TFontObject> TFontsContainer;

class ITFontsFromTStyleSheet
{
public:
virtual TString save() const = 0;
};

class ITFontsFromTFont
{
public:
virtual void erase(TFontsContainer::iterator it) = 0;
virtual TFontsContainer::const_iterator begin() const = 0;
};

#include "cfont.h"

class CFonts:
    public ITFontsFromTStyleSheet,
    public ITFontsFromTFont,
    protected TFontsContainer
{
protected:
typedef TFontsContainer base;

TString save() const;
void    erase(base::iterator it);
base::const_iterator begin() const;

public:
        CFonts();
TFont   insert();
TFont   insert(TString name, int size, TFontFlags flags);
};

#endif

