#include "cborder.h"

CBorder::CBorder():
    m_borders( NULL )
{
}

CBorder::CBorder(ITBordersFromTBorder& borders, const TBordersContainer::iterator& it):
    base( it ), m_borders( &borders )
{
Link();
}

CBorder::CBorder(const CBorder& origin):
    base( origin ), m_borders( origin.m_borders )
{
Link();
}

CBorder::~CBorder()
{
UnLink();
}

void CBorder::Link() const
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

void CBorder::UnLink() const
{
if ( IsSet() )
    {
    (*this)->UnLink();
    }
}

CBorder& CBorder::operator = (const CBorder& rvalue)
{
rvalue.Link();
UnLink();
base::operator = ( rvalue );
m_borders = rvalue.m_borders;
return *this;
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

