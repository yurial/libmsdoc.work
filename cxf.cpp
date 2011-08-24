#include "cxf.h"

CXF::CXF()
{
}

CXF::CXF(const TFont& font, const TFill& fill, const TBorder& border/*, const TNumFmt& numfmt*/):
    m_font( font ), m_fill( fill ), m_border( border )/*,const TNumFmt& numfmt*/
{
}

bool CXF::operator < (const CXF& rvalue) const
{
if ( m_font < rvalue.m_font )
    {
    return true;
    }
else if ( rvalue.m_font < m_font )
    {
    return false;
    }
else if ( m_fill < rvalue.m_fill )
    {
    return true;
    }
else if ( rvalue.m_fill < m_fill )
    {
    return false;
    }
else if ( m_border < rvalue.m_border )
    {
    return true;
    }
else if ( rvalue.m_border < m_border)
    {
    return false;
    }
return false;
}

