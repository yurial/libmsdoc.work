#include <assert.h>
#include "ccellvalue.h"

CCellValue::CCellValue()
{
m_value = NULL;
m_type = ECV_NONE;
}

CCellValue::~CCellValue()
{
clean();
}

void CCellValue::clean()
{
switch ( m_type )
    {
    case ECV_STRING:
        delete (TString*)m_value;
        break;
    case ECV_SHAREDSTRING:
        delete (TSharedString*)m_value;
        break;
    case ECV_FORMULA:
        delete (TFormula*)m_value;
        break;
    case ECV_INT:
        delete (int*)m_value;
        break;
    case ECV_DOUBLE:
        delete (double*)m_value;
        break;
    case ECV_NONE:
        break;
    default:
        assert( false );
    }
m_value = NULL;
m_type = ECV_NONE;
}

CCellValue& CCellValue::operator = (const TString& string)
{
clean();
m_value = new TString( string );
m_type = ECV_STRING;
return *this;
}

CCellValue& CCellValue::operator = (const TSharedString& sharedstring)
{
clean();
m_value = new TSharedString( sharedstring );
m_type = ECV_SHAREDSTRING;
return *this;
}

CCellValue& CCellValue::operator = (const TFormula& formula)
{
clean();
m_value = new TFormula( formula );
m_type = ECV_FORMULA;
return *this;
}

CCellValue& CCellValue::operator = (const int value)
{
clean();
m_value = new int( value );
m_type = ECV_INT;
return *this;
}

CCellValue& CCellValue::operator = (const double value)
{
clean();
m_value = new double( value );
m_type = ECV_DOUBLE;
return *this;
}

