#include <sstream>
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

TString CCellObject::s() const
{
std::stringstream s;
ITCellXFFromTCellObject& icellxf = (ITCellXFFromTCellObject&)m_cellxf;
if ( icellxf.IsSet() )
    {
    s << " s=\"" << icellxf.id() << '\"';
    }
return s.str();
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

CCellObject& CCellObject::operator = (const TCellXF& cellxf)
{
m_cellxf = cellxf;
return *this;
}

int CCellObject::save(std::stringstream& row) const
{
if ( ECV_NONE == TCellValue::m_type )
    {
    return 0;
    }

row << "<c r=\"" << cell() << "\"" << t() << s() << ">";
switch ( TCellValue::m_type )
    {
    case ECV_STRING:
        {
        row << "<is><t>" << *(const TString*)TCellValue::m_value << "</t></is>";
        }
        break;
    case ECV_SHAREDSTRING:
        {
        row << "<v>" << ((const ITSharedStringFromTCellObject*)TCellValue::m_value)->id() << "</v>";
        }
        break;
    case ECV_FORMULA:
        {
        row << "<f>" << ((const TFormula*)TCellValue::m_value)->c_str() << "</f>";
        }
        break;
    case ECV_INT:
        {
        row << "<v>" << *(const int*)TCellValue::m_value << "</v>";
        }
        break;
    case ECV_DOUBLE:
        {
        row << "<v>" << *(const double*)TCellValue::m_value << "</v>";
        }
        break;
    case ECV_DATE:
        {
        row << "<v>" << ((const TDate*)TCellValue::m_value)->c_str() << "</v>";
        }
    case ECV_NONE:
        break;
    }
row << "</c>";
return 0;
}

