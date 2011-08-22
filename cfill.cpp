#include "cfill.h"

CFill::CFill():
    m_fills( NULL )
{
}

CFill::CFill(ITFillsFromTFill& fills, const TFillsContainer::iterator& it):
    base( it ), m_fills( &fills )
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

CFill::CFill(const CFill& origin):
    base( origin ), m_fills( origin.m_fills )
{
if ( IsSet() )
    {
    (*this)->Link();
    }
}

CFill::~CFill()
{
if ( IsSet() )
    {
    (*this)->UnLink();
    }
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

