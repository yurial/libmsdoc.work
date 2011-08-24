#ifndef CBORDERLINEH
#define CBORDERLINEH

class CBorderLine;
typedef CBorderLine TBorderLine;

#include "cstring.h"
#include "ccolor.h"
#include "cborderstyle.h"

class CBorderLine
{
protected:
TColor          m_color;
EBORDERSTYLE    m_style;
public:
                CBorderLine();
                CBorderLine(EBORDERSTYLE style, const TColor& color);
                CBorderLine(EBORDERSTYLE style);
bool            operator <  (const CBorderLine& rvalue) const;
TString         save(const TString& tag) const;
bool            IsSet() const;
};

#endif

