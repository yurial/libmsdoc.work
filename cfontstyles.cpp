#include "cfontstyles.h"

TFontStyle CFontStyles::insert(TString name, int size, TFontFlags flags)
{
return base::insert( base::end(), TFontStyleObject( name, size, flags ) );
}

