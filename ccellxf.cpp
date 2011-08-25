#include "ccellxf.h"

CCellXF::CCellXF():
    m_cellxfs( NULL )
{
}

CCellXF::CCellXF(ITCellXFsFromTCellXF& cellxfs, const base& it):
    base( it ), m_cellxfs( &cellxfs )
{
Link();
}

CCellXF::CCellXF(const CCellXF& origin):
    base( origin ), m_cellxfs( origin.m_cellxfs )
{
Link();
}

CCellXF::~CCellXF()
{
UnLink();
}

void CCellXF::Link() const
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

void CCellXF::UnLink() const
{
if ( IsSet() && 0 == (*this)->UnLink() )
    {
    (*this)->UnLink();
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

