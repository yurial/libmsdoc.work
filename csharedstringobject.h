#ifndef CSHAREDSTRINGOBJECTH
#define CSHAREDSTRINGOBJECTH

#include "cstring.h"
#include "cformula.h"

class CSharedStringObject;
typedef CSharedStringObject TSharedStringObject;

class CSharedStringObject:
    public std::string
{
private:
CSharedStringObject& operator = (const CSharedStringObject&);

protected:
using std::string::operator =;

public:
        CSharedStringObject(const TString& string);
};

#endif

