#ifndef CFONTH
#define CFONTH

class CFont;
typedef CFont TFont;

#include "cfonts.h"
#include "cfontobject.h"

class CFont:
    protected TFontsContainer::iterator
{
protected:
typedef TFontsContainer::iterator base;
using base::operator ->;

ITFontsFromTFont& m_fonts;

public:
    CFont(ITFontsFromTFont& fonts, const base& it);
    CFont(const CFont& origin);
    ~CFont();
};

#endif

