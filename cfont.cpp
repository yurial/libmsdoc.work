#include <signal.h>
#include "cfont.h"

CFont::CFont(ITFontsFromTFont& fonts, const base& it):
    base( it ), m_fonts( fonts )
{
(*this)->Link();
}

CFont::CFont(const CFont& origin):
    base( origin ), m_fonts( origin.m_fonts )
{
(*this)->Link();
}

CFont::~CFont()
{
if ( 0 == (*this)->UnLink() )
    {
    m_fonts.erase( *this );
    }
}

