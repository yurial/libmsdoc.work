#include "csharedstring.h"

CSharedString::CSharedString(const base& it):
    base( it )
{
}

int CSharedString::id() const
{
return (*this)->second;
};

