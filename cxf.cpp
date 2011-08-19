#include "cxf.h"

CXF::CXF()
{
}

CXF::CXF(const TFont& font/*,const TFill& fill*//*,const TBorder& border*//*,const TNumFmt& numfmt*/):
    m_font( font )/*,const TFill& fill*//*,const TBorder& border*//*,const TNumFmt& numfmt*/
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
/*
else if ()
*/
return false;
}

