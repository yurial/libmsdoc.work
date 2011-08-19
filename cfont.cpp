#include <signal.h>
#include "cfont.h"

CFont::CFont():
    m_fonts( NULL )
{
}

CFont::CFont(ITFontsFromTFont& fonts, const base& it):
    base( it ), m_fonts( &fonts )
{
(*this)->Link();
}

CFont::CFont(const CFont& origin):
    base( origin ), m_fonts( origin.m_fonts )
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

CFont::~CFont()
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

