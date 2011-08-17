#include "csharedstring.h"

CSharedString::CSharedString(ITSharedStringsFromTSharedString& sharedstrings, const base& it):
    base( it ), m_sharedstrings( sharedstrings )
{
(*this)->Link();
}

CSharedString::CSharedString(const CSharedString& origin):
    base( origin ), m_sharedstrings( origin.m_sharedstrings )
{
(*this)->Link();
}

CSharedString::~CSharedString()
{
if ( 0 == (*this)->UnLink() )
    {
    m_sharedstrings.erase( *this );
    }
}

int CSharedString::id() const
{
return ((const ITSharedStringObjectFromTSharedString&)this->operator *()).id();
};

