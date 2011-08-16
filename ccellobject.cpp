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
}

CCellObject::~CCellObject()
{
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

int CCellObject::save(std::stringstream& row) const
{
switch ( TCellValue::m_type )
    {
    case ECV_STRING:
        {
        row << "<c r=\"" << cell() << "\" t=\"inlineStr\"><is><t>" << *(const TString*)TCellValue::m_value << "</t></is></c>";
        }
        break;
    case ECV_SHAREDSTRING:
        {
        row << "<c r=\"" << cell() << "\" t=\"s\"><v>" << ((const ITSharedStringFromTCellObject*)TCellValue::m_value)->id() << "</v></c>";
        }
        break;
    case ECV_FORMULA:
        {
        row << "<c r=\"" << cell() << "\"><f>" << ((const TFormula*)TCellValue::m_value)->c_str() << "</f></c>";
        }
        break;
    case ECV_INT:
        {
        row << "<c r=\"" << cell() << "\"><v>" << *(const int*)TCellValue::m_value << "</v></c>";
        }
        break;
    case ECV_DOUBLE:
        {
        row << "<c r=\"" << cell() << "\"><v>" << *(const double*)TCellValue::m_value << "</v></c>";
        }
        break;
    case ECV_NONE:
        break;
    }
return 0;
}

