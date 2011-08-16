#ifndef CWORKBOOKLISTH
#define CWORKBOOKLISTH

#include <list>

class CWorkBookList;
typedef CWorkBookList TWorkBookList;

#include "cworkbooklistobject.h"

class CWorkBookList:
    public std::list<TWorkBookListObject>::iterator
{
protected:
typedef std::list<TWorkBookListObject>::iterator base;
using base::operator ->;

public:
            CWorkBookList(const base& it);
            CWorkBookList(const CWorkBookList& origin);

TString&    name();
};

#endif

