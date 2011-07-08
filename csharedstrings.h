#ifndef CSHAREDSTRINGSH
#define CSHAREDSTRINGSH

#include <map>

class CSharedStrings;
typedef CSharedStrings TSharedStrings;

#include "csharedstring.h"

class CSharedStrings:
    protected std::map<TSharedStringObject,int>
{
protected:
typedef std::map<TSharedStringObject,int> base;

public:

TSharedString   add(const TString& string);
TSharedString   add(const TFormula& formula);
void            erase(TSharedString& sharedstring);
using           base::size;
};

#endif

