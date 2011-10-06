#include "cnumfmt.h"

CNumFmt::CNumFmt():
    m_numfmts( NULL )
{
}

CNumFmt::CNumFmt(ITNumFmtsFromTNumFmt& numfmts, const base& it):
    base( it ), m_numfmts( &numfmts )
{
Link();
}

CNumFmt::CNumFmt(const CNumFmt& origin):
    base( origin ), m_numfmts( origin.m_numfmts )
{
Link();
}

CNumFmt::~CNumFmt()
{
UnLink();
}

void CNumFmt::Link() const
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

void CNumFmt::UnLink() const
{
if ( IsSet() && 0 == (*this)->UnLink() )
    {
    m_numfmts->erase( *this );
    }
}

CNumFmt& CNumFmt::operator |= (const CNumFmt& rvalue)
{
if ( rvalue.IsSet() )
    {
    this->base::operator = ( rvalue );
    }
return *this;
}

CNumFmt& CNumFmt::operator = (const CNumFmt& rvalue)
{
rvalue.Link();
UnLink();
base::operator = ( rvalue );
m_numfmts = rvalue.m_numfmts;
return *this;
}

bool CNumFmt::operator <  (const CNumFmt& rvalue) const
{
return id() < rvalue.id();
}

int CNumFmt::id() const
{
if ( !IsSet() )
    {
    return -1;
    }

return ((const ITNumFmtObjectFromTNumFmt&)this->operator * ()).id();
}

bool CNumFmt::IsSet() const
{
return NULL != _M_node;
}

