#ifndef CFORMULAH
#define CFORMULAH

class CFormula;
typedef CFormula TFormula;

#include "cstring.h"

class CFormula:
    public TString
{
public:
    CFormula(const TString& formula);
};

#endif

