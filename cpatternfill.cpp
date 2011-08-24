#include <sstream>
#include <map>
#include "cinitializer.h"
#include "cpatternfill.h"

std::map<EPATTERN,TString>  g_patterntypes;

struct SPatternString
{
public:
EPATTERN    m_pattern;
TString     m_str;
};

SPatternString g_patterns[] = {
    { EPATTERN_NONE,            "none"          },
    { EPATTERN_SOLID,           "solid"         },

    { EPATTERN_DARKDOWN,        "darkDown"      },
    { EPATTERN_DARKGRAY,        "darkGray"      },
    { EPATTERN_DARKGRID,        "darkGrid"      },
    { EPATTERN_DARKHORIZONTAL,  "darkHorizontal"},
    { EPATTERN_DARKTRELLIS,     "darkTrellis"   },
    { EPATTERN_DARKUP,          "darkUp"        },
    { EPATTERN_DARKVERTICAL,    "darkVertical"  },

    { EPARRERN_GRAY0625,        "gray0625"      },
    { EPATTERN_GRAY125,         "gray125"       },

    { EPATTERN_LIGHTDOWN,       "lightDown"     },
    { EPATTERN_LIGHTGRAY,       "lightGray"     },
    { EPATTERN_LIGHTGRID,       "lightGrid"     },
    { EPATTERN_LIGHTHORIZONTAL, "lightHorizontal"   },
    { EPATTERN_LIGHTTRELLIS,    "lightTrellis"  },
    { EPATTERN_LIGHTUP,         "lightUp"       },
    { EPATTERN_LIGTVERTICAL,    "lightVertical" },

    { EPATTERN_MEDIUMGRAY,      "mediumGray"    },
};

static void patterntypes_init_f()
{
for (unsigned int pos = 0; pos < sizeof(g_patterns)/sizeof(SPatternString); ++pos)
    {
    g_patterntypes[ g_patterns[ pos ].m_pattern ] = g_patterns[ pos ].m_str;
    }
}

static TInitializer g_patterntype_init( patterntypes_init_f );

CPatternFill::CPatternFill():
    m_pattern( EPATTERN_NONE )
{
}

CPatternFill::CPatternFill(const TColor& fg, const TColor& bg, EPATTERN pattern):
    m_fg( fg ), m_bg( bg ), m_pattern( pattern )
{
}

bool CPatternFill::operator <  (const CPatternFill& rvalue) const
{
if ( m_pattern < rvalue.m_pattern )
    {
    return true;
    }
else if ( rvalue.m_pattern < m_pattern )
    {
    return false;
    }
else if ( m_fg < rvalue.m_fg )
    {
    return true;
    }
else if ( rvalue.m_fg < m_fg )
    {
    return false;
    }
else if ( m_bg < rvalue.m_bg )
    {
    return true;
    }
else if ( rvalue.m_bg < m_bg )
    {
    return false;
    }
return false;
}

TString CPatternFill::save() const
{
if ( !IsSet() )
    {
    return TString();
    }

std::stringstream fill;
fill << "<patternFill patternType=\"";
fill << g_patterntypes[ m_pattern ];
fill << "\">\n";

if ( m_fg.IsSet() )
    {
    fill << "<fgColor";
    fill << m_fg.save();
    fill << "/>\n";
    }

if ( m_bg.IsSet() )
    {
    fill << "<bgColor";
    fill << m_bg.save();
    fill << "/>\n";
    }

fill << "</patternFill>\n";
return fill.str();
}

bool CPatternFill::IsSet() const
{
return EPATTERN_NONE != m_pattern || m_fg.IsSet() || m_bg.IsSet();
}

