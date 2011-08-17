#ifndef CFONTSH
#define CFONTSH

#include <list>

class CFonts;
typedef CFonts TFonts;

#include "cfont.h"
#include "cfontobject.h"

class CFonts:
    protected std::list<TFontObject>
{
protected:
typedef std::list<TFontObject> base;

public:
TFont   insert(TString name, int size, TFontFlags flags);
};

#endif

