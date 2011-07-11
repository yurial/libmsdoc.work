#include "csharedstring.h"

CSharedString::CSharedString(const base& it):
    base( it )
{
}

int CSharedString::id()
{
return (*this)->second;
};

