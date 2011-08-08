#include "ccellobject.h"

TString ToStrId(int id)
{
int base = ('Z'-'A'+1);
TString col;

TString sym;
sym += id % base + 'A';
col = sym + col;
id /= base;
++base;

while ( id )
    {
    TString sym;
    sym += id % base + 'A';
    col = sym + col;
    id /= base;
    }
if ( 1 < col.size() )
    {
    --col[0];
    }
return col;
#undef base
}

int FromStrId(const TString& str)
{
TString col( str );
int base = ('Z'-'A'+2);
int index = 0;
int power = 1;
if ( 1 < col.size() )
    {
    ++col[0];
    }
int pos = col.size()-1;
while ( 0 < pos )
    {
    register int value = col[ pos ] - 'A';
    value *= power;
    index += value;
    --pos;
    if ( 0 < pos )
        {
        power *= base;
        }
    else
        {
        power *= base - 1;
        break;
        }
    }
index += (col[ 0 ] - 'A') * power;
return index;
#undef base
}

CCellObject::CCellObject(TRowObject& row, int id):
    m_row( row ), m_id( id )
{
m_shastr = NULL;
m_str = NULL;
}

CCellObject::~CCellObject()
{
if ( NULL != m_str )
    {
    delete m_str;
    #ifdef DEBUG
    m_str = NULL;
    #endif
    }
if ( NULL != m_shastr )
    {
    delete m_shastr;
    #ifdef DEBUG
    m_shastr = NULL;
    #endif
    }
}

int CCellObject::id() const
{
return m_id;
}

TString CCellObject::col() const
{
return ToStrId( m_id );
}

TString CCellObject::cell() const
{
std::stringstream str;
str << col() << m_row.row();
return str.str();
}

CCellObject& CCellObject::operator = (const TString& str)
{

if ( NULL != m_str )
    {
    delete m_str;
    }
if ( NULL != m_shastr )
    {
    delete m_shastr;
    m_shastr = NULL;
    }
m_str = new TString( str );
return *this;
}

CCellObject& CCellObject::operator = (const TSharedString& str)
{
if ( NULL != m_str )
    {
    delete m_str;
    m_str = NULL;
    }
if ( NULL != m_shastr )
    {
    delete m_shastr;
    }
m_shastr = new TSharedString( str );
return *this;
}

int CCellObject::save(std::stringstream& row) const
{
row << "<c r=\"" << cell() << "\"><v>1</v></c>";
return 0;
}

