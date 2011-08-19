#include "csharedstringobject.h"


ITSharedStringObjectFromTSharedStrings::ITSharedStringObjectFromTSharedStrings():
    m_id( -1 )
{
}

ITSharedStringObjectFromTSharedStrings::ITSharedStringObjectFromTSharedStrings(const ITSharedStringObjectFromTSharedStrings& origin):
    m_id( origin.m_id )
{
}
        
void ITSharedStringObjectFromTSharedStrings::SetId(int id)
{
m_id = id;
}

int ITSharedStringObjectFromTSharedStrings::GetId() const
{
return m_id;
}

void ITSharedStringObjectFromTSharedStrings::operator ++ ()
{
++m_id;
}

void ITSharedStringObjectFromTSharedStrings::operator -- ()
{
--m_id;
}

ITSharedStringObjectFromTSharedString::ITSharedStringObjectFromTSharedString():
    m_links( 0 )
{
}

ITSharedStringObjectFromTSharedString::ITSharedStringObjectFromTSharedString(const ITSharedStringObjectFromTSharedString& origin):
    m_links( origin.m_links )
{
}

void ITSharedStringObjectFromTSharedString::Link() const
{
++m_links;
}

int ITSharedStringObjectFromTSharedString::UnLink() const
{
return --m_links;
}

CSharedStringObject::CSharedStringObject(const TString& string):
    TString( string )
{
}

CSharedStringObject::CSharedStringObject(const CSharedStringObject& origin):
    ITSharedStringObjectFromTSharedStrings( origin ),
    ITSharedStringObjectFromTSharedString( origin ),
    TString( origin )
{
}

TString CSharedStringObject::save() const
{
return *this;
}

int CSharedStringObject::id() const
{
return ITSharedStringObjectFromTSharedStrings::GetId();
}

bool CSharedStringObject::operator < (const CSharedStringObject& rvalue) const
{
return std::less<TString>()( *this, rvalue );
}

