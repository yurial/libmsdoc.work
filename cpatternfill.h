#ifndef CPATTERNH
#define CPATTERNH

class CPatternFill;
typedef CPatternFill TPatternFill;

enum EPATTERN
{
EPATTERN_NONE,  //none

EPATTERN_GRAY125,   //gray125 (Gray 0.125)
EPARRERN_GRAY0625,  //gray0625 (Gray 0.0625)

EPATTERN_SOLID, //solid

EPATTERN_DARKDOWN,  //darkDown (Dark Down)
EPATTERN_DARKGRAY,  //darkGray (Dary Gray)
EPATTERN_DARKGRID,  //darkGrid (Dark Grid)
EPATTERN_DARKHORIZONTAL,//darkHorizontal (Dark Horizontal)
EPATTERN_DARKTRELLIS,   //darkTrellis (Dark Trellis)
EPATTERN_DARKUP,        //darkUp (Dark Up)
EPATTERN_DARKVERTICAL,  //darkVertical (Dark Vertical)

EPATTERN_LIGHTDOWN, //lightDown (Light Down)
EPATTERN_LIGHTGRAY, //lightGray (Light Gray)
EPATTERN_LIGHTGRID, //lightGrid (Light Grid)
EPATTERN_LIGHTHORIZONTAL,   //lightHorizontal (Light Horizontal)
EPATTERN_LIGHTTRELLIS,      //lightTrellis (Light Trellis)
EPATTERN_LIGHTUP,   //lightUp (Light Up)
EPATTERN_LIGTVERTICAL,  //lightVertical (Light Vertical)

EPATTERN_MEDIUMGRAY,    //mediumGray (Medium Gray)
};

#include "ccolor.h"
#include "cstring.h"

class ITPatternFillFromTFillObject
{
public:
virtual TString save() const = 0;
virtual bool operator <  (const CPatternFill& rvalue) const = 0;
};

class CPatternFill:
    public ITPatternFillFromTFillObject
{
protected:
TColor          m_fg;       //bgColor (Background Color) §18.8.3
TColor          m_bg;       //fgColor (Foreground Color) §18.8.19
EPATTERN        m_pattern;  //patternType (Pattern Type) §18.18.55

/* ITPatternFillFromTFillObject */
bool    operator <  (const CPatternFill& rvalue) const;
TString save() const;

public:
        CPatternFill();
        CPatternFill(const TColor& fg, const TColor& bg, EPATTERN pattern);
bool    IsSet() const;
};

#endif

