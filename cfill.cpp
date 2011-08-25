#include "cfill.h"

CFill::CFill():
    m_fills( NULL )
{
}

CFill::CFill(ITFillsFromTFill& fills, const TFillsContainer::iterator& it):
    base( it ), m_fills( &fills )
{
Link();
}

CFill::CFill(const CFill& origin):
    base( origin ), m_fills( origin.m_fills )
{
Link();
}

CFill::~CFill()
{
UnLink();
}

void CFill::Link() const
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

void CFill::UnLink() const
{
if ( IsSet() )
    {
    (*this)->UnLink();
    }
}

CFill& CFill::operator = (const CFill& rvalue)
{
rvalue.Link();
UnLink();
base::operator = ( rvalue );
m_fills = rvalue.m_fills;
return *this;
}

bool CFill::operator <  (const CFill& rvalue) const
{
return id() < rvalue.id();
}

int CFill::id() const
{
if ( !IsSet() )
    {
    return -1;
    }

return ((ITFillObjectFromTFill&)this->operator *()).id();
}

bool CFill::IsSet() const
{
return NULL != _M_node;
}

