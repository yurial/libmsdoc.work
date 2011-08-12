#ifndef CFORMULAH
#define CFORMULAH

class CFormula;
typedef CFormula TFormula;

#include "cstring.h"

class CFormula:
    protected TString
{
public:
    CFormula(const TString& formula);
    using TString::c_str;
};

#endif

