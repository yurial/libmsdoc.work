#ifndef CCOLORH
#define CCOLORH

class CColor;
typedef CColor TColor;

#include "cstring.h"

class CColor
{
protected:
int     m_rgb;

public:
        CColor();
        CColor(int rgb);

bool    operator <  (const CColor& rvalue) const;

TString save() const;
};

#endif

