#include "cfonts.h"

TFont CFonts::insert(TString name, int size, TFontFlags flags)
{
return base::insert( base::end(), TFontObject( name, size, flags ) );
}

