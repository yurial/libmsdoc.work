#include "cfont.h"

CFont::CFont():
    m_fonts( NULL )
{
}

CFont::CFont(ITFontsFromTFont& fonts, const base& it):
    base( it ), m_fonts( &fonts )
{
Link();
}

CFont::CFont(const CFont& origin):
    base( origin ), m_fonts( origin.m_fonts )
{
Link();
}

CFont::~CFont()
{
UnLink();
}

void CFont::Link() const
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

void CFont::UnLink() const
{
if ( IsSet() && 0 == (*this)->UnLink() )
    {
    m_fonts->erase( *this );
    }
}

CFont& CFont::operator |= (const CFont& rvalue)
{
if ( rvalue.IsSet() )
    {
    this->base::operator = ( rvalue );
    }
return *this;
}

CFont& CFont::operator = (const CFont& rvalue)
{
rvalue.Link();
UnLink();
base::operator = ( rvalue );
m_fonts = rvalue.m_fonts;
return *this;
}

bool CFont::operator <  (const CFont& rvalue) const
{
return id() < rvalue.id();
}

int CFont::id() const
{
if ( !IsSet() )
    {
    return -1;
    }

return ((const ITFontObjectFromTFont&)this->operator *()).id();
}

bool CFont::IsSet() const
{
return NULL != _M_node;
}

