#ifndef CFONTSTYLESH
#define CFONTSTYLESH

#include <list>

class CFontStyles;
typedef CFontStyles TFontStyles;

#include "cfontstyle.h"
#include "cfontstyleobject.h"

class CFontStyles:
    protected std::list<TFontStyleObject>
{
protected:
typedef std::list<TFontStyleObject> base;

public:
TFontStyle  insert(TString name, int size, TFontFlags flags);
};

#endif

