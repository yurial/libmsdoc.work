#include "cxf.h"

CXF::CXF()
{
}

CXF::CXF(const TFont& font, const TAlignment& align, const TBorder& border, const TFill& fill, const TNumFmt& numfmt):
    m_align( align ), m_font( font ), m_fill( fill ), m_border( border ), m_numfmt( numfmt )
{
}

bool CXF::operator < (const CXF& rvalue) const
{
if ( m_align < rvalue.m_align )
    {
    return true;
    }
else if ( rvalue.m_align < m_align )
    {
    return false;
    }
else if ( m_font < rvalue.m_font )
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
else if ( m_numfmt < rvalue.m_numfmt )
    {
    return true;
    }
else if ( rvalue.m_numfmt < m_numfmt )
    {
    return false;
    }
return false;
}

