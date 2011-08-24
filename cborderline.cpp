#include <sstream>
#include <map>
#include "cinitializer.h"
#include "cborderline.h"

static std::map<EBORDERSTYLE,TString>  g_styles;

struct SBorderStyle
{
EBORDERSTYLE    m_style;
TString         m_stylename;
};

SBorderStyle g_stylesarr[] = {
    { EBORDERSTYLE_NONE,            "none"              },
    { EBORDERSTYLE_DASHDOT,         "dashDot"           },
    { EBORDERSTYLE_DASHDOTDOT,      "dashDotDot"        },
    { EBORDERSTYLE_DASHED,          "dashed"            },
    { EBORDERSTYLE_DOTTED,          "dotted"            },
    { EBORDERSTYLE_DOUBLE,          "double"            },
    { EBORDERSTYLE_HAIR,            "hair"              },
    { EBORDERSTYLE_MEDIUM,          "medium"            },
    { EBORDERSTYLE_MEDIUMDASHDOT,   "mediumDashDot"     },
    { EBORDERSTYLE_MEDIUMDASHDOTDOT,"mediumdashDotDot"  },
    { EBORDERSTYLE_MEDIUMDASHED,    "mediumDashed"      },
    { EBORDERSTYLE_SLANTDASHDOT,    "slantDashDot"      },
    { EBORDERSTYLE_THINCK,          "thinck"            },
    { EBORDERSTYLE_THIN,            "thin"              },
};

void borderstyle_init_f()
{
for (unsigned int pos = 0; pos < sizeof(g_stylesarr)/sizeof(SBorderStyle); ++pos)
    {
    g_styles.insert( std::make_pair( g_stylesarr[ pos ].m_style, g_stylesarr[ pos ].m_stylename ) );
    }
}

TInitializer borderstyle_init( borderstyle_init_f );

CBorderLine::CBorderLine():
    m_style( EBORDERSTYLE_NONE )
{
}

CBorderLine::CBorderLine(EBORDERSTYLE style):
    m_style( style )
{
}

CBorderLine::CBorderLine(EBORDERSTYLE style, const TColor& color):
    m_color( color ), m_style( style )
{
}

bool CBorderLine::operator < (const CBorderLine& rvalue) const
{
if ( m_style < rvalue.m_style )
    {
    return true;
    }
else if ( rvalue.m_style < m_style )
    {
    return false;
    }
else if ( m_color < rvalue.m_color )
    {
    return true;
    }
else if ( rvalue.m_color < m_color )
    {
    return false;
    }
return false;
}

TString CBorderLine::save(const TString& tag) const
{
if ( !IsSet() )
    {
    return TString();
    }
std::stringstream border;
border << '<' << tag << " style=\"" << g_styles[ m_style ] << '\"';
if ( m_color.IsSet() )
    {
    border << '>' << '\n';
    border << "<color" << m_color.save() << '/' << '>' << '\n';
    border << '<' << '/' << tag << '>' << '\n';
    }
else
    {
    border << '/' << '>' << '\n';
    }
return border.str();
}

bool CBorderLine::IsSet() const
{
return EBORDERSTYLE_NONE != m_style || m_color.IsSet();
}

