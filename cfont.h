#ifndef CFONTH
#define CFONTH

class CFont;
typedef CFont TFont;

#include "cfonts.h"
#include "cfontobject.h"

class ITFontFromTCellXFObject
{
public:
virtual int id() const = 0;
virtual bool IsSet() const = 0;
};

class CFont:
    public ITFontFromTCellXFObject,
    protected TFontsContainer::iterator
{
protected:
typedef TFontsContainer::iterator base;
using base::operator ->;

ITFontsFromTFont*   m_fonts;

int     id() const;
bool    IsSet() const;

public:
        CFont();
        CFont(ITFontsFromTFont& fonts, const base& it);
        CFont(const CFont& origin);
        ~CFont();

CFont&  operator |= (const CFont& rvalue);
bool    operator <  (const CFont& rvalue) const;
};

#endif

