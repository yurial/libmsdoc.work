#include "cborder.h"

CBorder::CBorder():
    m_borders( NULL )
{
}

CBorder::CBorder(ITBordersFromTBorder& borders, const TBordersContainer::iterator& it):
    base( it ), m_borders( &borders )
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

CBorder::CBorder(const CBorder& origin):
    base( origin ), m_borders( origin.m_borders )
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

CBorder::~CBorder()
{
if ( IsSet() )
    {
    (*this)->UnLink();
    }
}

bool CBorder::operator < (const CBorder& rvalue) const
{
return id() < rvalue.id();
}

int CBorder::id() const
{
if ( !IsSet() )
    {
    return -1;
    }

return ((ITBorderObjectFromTBorder&)this->operator *()).id();
}

bool CBorder::IsSet() const
{
return NULL != _M_node;
}

