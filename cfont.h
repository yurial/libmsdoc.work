#ifndef CFONTH
#define CFONTH

#include <list>

class CFont;
typedef CFont TFont;

#include "cfontobject.h"

class CFont:
    protected std::list<TFontObject>::iterator
{
protected:
typedef std::list<TFontObject>::iterator base;

public:
            CFont(const base& it);
};

#endif

