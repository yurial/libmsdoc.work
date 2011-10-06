#include <sstream>
#include <map>
#include "calignment.h"
#include "cinitializer.h"

struct SEnumStr
{
int     m_id;
TString m_value;
};

SEnumStr    g_horizontals_arr[] = {
    { EHORIZONTAL_CENTER,           "center"            },
    { EHORIZONTAL_CENTERCONTINOUS,  "centerContinuous"  },
    { EHORIZONTAL_DISTRIBUTED,      "distributed"       },
    { EHORIZONTAL_FILL,             "fill"              },
    { EHORIZONTAL_GENERAL,          "general"           },
    { EHORIZONTAL_JUSTIFY,          "justify"           },
    { EHORIZONTAL_LEFT,             "left"              },
    { EHORIZONTAL_RIGHT,            "right"             },
};

SEnumStr    g_verticals_arr[] = {
    { EVERTICAL_BOTTOM,             "bottom"            },
    { EVERTICAL_CENTER,             "center"            },
    { EVERTICAL_DISTRIBUTED,        "distributed"       },
    { EVERTICAL_JUSTIFY,            "justify"           },
    { EVERTICAL_TOP,                "top"               },
};

std::map<int,TString>   g_horizontals;
std::map<int,TString>   g_verticals;

static void alignment_init_f()
{
for (unsigned int pos = 0; pos < sizeof(g_horizontals_arr)/sizeof(SEnumStr); ++pos)
    {
    g_horizontals.insert( std::make_pair( g_horizontals_arr[ pos ].m_id, g_horizontals_arr[ pos ].m_value ) );
    }

for (unsigned int pos = 0; pos < sizeof(g_verticals_arr)/sizeof(SEnumStr); ++pos)
    {
    g_verticals.insert( std::make_pair( g_verticals_arr[ pos ].m_id, g_verticals_arr[ pos ].m_value ) );
    }
}

TInitializer alignment_init( alignment_init_f );

CAlignment::CAlignment(EHORIZONTAL horizontal, EVERTICAL vertical, bool wrap, bool shrink, uint rotation, int indent):
    m_horizontal( horizontal ), m_vertical( vertical ), m_wrap( wrap ), m_shrink( shrink ), m_rotation( rotation ), m_indent( indent )
{
}

bool CAlignment::operator <  (const CAlignment& rvalue) const
{
if ( m_horizontal < rvalue.m_horizontal )
    {
    return true;
    }
else if ( rvalue.m_horizontal < m_horizontal )
    {
    return false;
    }
else if ( m_vertical < rvalue.m_vertical )
    {
    return true;
    }
else if ( rvalue.m_vertical < m_vertical )
    {
    return false;
    }
else if ( m_wrap < rvalue.m_wrap )
    {
    return true;
    }
else if ( rvalue.m_wrap < m_wrap )
    {
    return false;
    }
else if ( m_shrink < rvalue.m_shrink )
    {
    return true;
    }
else if ( rvalue.m_shrink < m_shrink )
    {
    return false;
    }
else if ( m_indent < rvalue.m_indent )
    {
    return true;
    }
else if ( rvalue.m_indent < m_indent )
    {
    return false;
    }
else if ( m_rotation < rvalue.m_rotation )
    {
    return true;
    }
else if ( rvalue.m_rotation < m_rotation )
    {
    return false;
    }
return false;
}

TString CAlignment::save(const TString& tag) const
{
std::stringstream alignment;
alignment << '<' << tag;
alignment << " horizontal=\"" << g_horizontals[ m_horizontal ] << '\"';
alignment << " indent=\"" << m_indent << '\"';
alignment << " justifyLastLine=\"" << '0' << '\"';
alignment << " readingOrder=\"" << '0' << '\"';
alignment << " relativeIndent=\"" << '0' << '\"';
alignment << " shrinkToFit=\"" << m_shrink << '\"';
alignment << " textRotation=\"" << m_rotation << '\"';
alignment << " vertical=\"" << g_verticals[ m_vertical ] << '\"';
alignment << " wrapText=\"" << m_wrap << '\"';
alignment << '/' << '>' << '\n';
return alignment.str();
}

