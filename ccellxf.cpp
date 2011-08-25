#include "ccellxf.h"

CCellXF::CCellXF():
    m_cellxfs( NULL )
{
}

CCellXF::CCellXF(ITCellXFsFromTCellXF& cellxfs, const base& it):
    base( it ), m_cellxfs( &cellxfs )
{
(*this)->Link();
}

CCellXF::CCellXF(const CCellXF& origin):
    base( origin ), m_cellxfs( origin.m_cellxfs )
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

CCellXF::~CCellXF()
{
if ( IsSet() && 0 == (*this)->UnLink() )
    {
    m_cellxfs->erase( *this );
    }
}

CCellXF& CCellXF::operator = (const CCellXF& rvalue)
{
rvalue.Link();
UnLink();
base::operator = ( rvalue );
m_cellxfs = rvalue.m_cellxfs;
return *this;
}

int CCellXF::id() const
{
return ((const ITCellXFObjectFromTCellXF&)this->operator *()).id();
}

bool CCellXF::IsSet() const
{
return NULL != base::_M_node;
}

