#ifndef CCOLORH
#define CCOLORH

class CColor;
typedef CColor TColor;

#include "cstring.h"

class CColor
{
protected:
bool    m_set;
int     m_rgb;

public:
        CColor();
        CColor(int rgb);

bool    operator <  (const CColor& rvalue) const;

TString save() const;
bool    IsSet() const;
};

#endif

