#ifndef CFONTSTYLEH
#define SFONTSTYLEH

#include <list>

class CFontStyle;
typedef CFontStyle TFontStyle;

#include "cfontstyleobject.h"

class CFontStyle:
    protected std::list<TFontStyleObject>::iterator
{
protected:
typedef std::list<TFontStyleObject>::iterator base;

public:
            CFontStyle(const base& it);
};

#endif

