#include "cworkbooklist.h"

CWorkBookList::CWorkBookList(const base& it):
    base( it )
{
}

CWorkBookList::CWorkBookList(const CWorkBookList& origin):
    base( origin )
{
}

TString& CWorkBookList::name()
{
return (*this)->name();
}

