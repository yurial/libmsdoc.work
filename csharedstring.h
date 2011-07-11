#ifndef CSHAREDSTRINGH
#define CSHAREDSTRINGH

#include <map>

class CSharedString;
typedef CSharedString TSharedString;

#include "csharedstringobject.h"

class CSharedString:
    public std::map<TSharedStringObject,int>::iterator
{
protected:
typedef std::map<TSharedStringObject,int>::iterator base;
using   base::operator ->;

public:
        CSharedString(const base& it);
int     id();
};

#endif

