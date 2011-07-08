#include "csharedstringobject.h"

CSharedStringObject::CSharedStringObject(const TString& string)
{
*this += "<si>" + string + "</si>";
}

CSharedStringObject::CSharedStringObject(const TFormula& formula)
{
*this += "<f>" + formula + "</f>";
}

