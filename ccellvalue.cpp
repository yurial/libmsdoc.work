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
    case ECV_DATE:
        delete (TDate*)m_value;
    case ECV_NONE:
        break;
    }
m_value = NULL;
m_type = ECV_NONE;
TCellType::SetType( ECT_NONE );
}

CCellValue& CCellValue::operator = (const TString& string)
{
clean();
m_value = new TString( string );
m_type = ECV_STRING;
TCellType::SetType( ECT_IS );
return *this;
}

CCellValue& CCellValue::operator = (const TSharedString& sharedstring)
{
clean();
m_value = new TSharedString( sharedstring );
m_type = ECV_SHAREDSTRING;
TCellType::SetType( ECT_SHARED_STRING );
return *this;
}

CCellValue& CCellValue::operator = (const TFormula& formula)
{
clean();
m_value = new TFormula( formula );
m_type = ECV_FORMULA;
TCellType::SetType( ECT_STR );
return *this;
}

CCellValue& CCellValue::operator = (const int value)
{
clean();
m_value = new int( value );
m_type = ECV_INT;
TCellType::SetType( ECT_NUMBER );
return *this;
}

CCellValue& CCellValue::operator = (const double value)
{
clean();
m_value = new double( value );
m_type = ECV_DOUBLE;
TCellType::SetType( ECT_NUMBER );
return *this;
}

CCellValue& CCellValue::operator = (const TDate& date)
{
clean();
m_value = new TDate( date );
m_type = ECV_DATE;
TCellType::SetType( ECT_DATE );
return *this;
}

