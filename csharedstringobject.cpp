#include "csharedstringobject.h"

CSharedStringObject::CSharedStringObject(const TString& string)
{
*this = string;
}

