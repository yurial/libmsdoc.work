#ifndef CCELLVALUEH
#define CCELLVALUEH

class CCellValue;
typedef CCellValue TCellValue;

#include "ccelltype.h"
#include "cstring.h"
#include "cformula.h"
#include "csharedstring.h"
#include "cdate.h"

enum ECV_TYPE
{
ECV_NONE,
ECV_STRING,
ECV_SHAREDSTRING,
ECV_FORMULA,
ECV_INT,
ECV_DOUBLE,
ECV_DATE,
};

class CCellValue:
    public TCellType
{
private:
protected:
void*       m_value;
ECV_TYPE    m_type;

public:
            CCellValue();
            ~CCellValue();

void        clean();

CCellValue& operator = (const TString& string);
CCellValue& operator = (const TSharedString& sharedstring);
CCellValue& operator = (const TFormula& formula);
CCellValue& operator = (const int value);
CCellValue& operator = (const double value);
CCellValue& operator = (const TDate& date);
};

#endif

