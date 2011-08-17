#ifndef CFONTOBJECTH
#define CFONTOBJECTH

class CFontObject;
typedef CFontObject TFontObject;

#include "cstring.h"
#include "cfontflags.h"

class CFontObject
{
protected:
TString     m_name;     //name (Font Name) 18.8.29
int         m_size;     //sz (Font Size) 18.4.11
TFontFlags  m_flags;
//TODO: TFontCharset    //charset (Character Set) 18.4.1
//TODO: TColor          //color (Data Bar Color) 18.3.1.15
//TODO: TFontFamily     //family (Font Family) 18.8.18
//TODO: TFontScheme     //scheme (Scheme) 18.8.35
//TODO: TVertalign      /vertAlign (Vertical Alignment) 18.4.14

public:
    CFontObject(TString name, int size, TFontFlags flags);
};

#endif

