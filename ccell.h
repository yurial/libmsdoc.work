#ifndef CCELLH
#define CCELLH

#include <map>

class CCell;
typedef CCell TCell;

#include "csharedstring.h"
#include "ccellobject.h"
typedef std::map<int,TCellObject> TCells;

class CCell:
    protected TCells::iterator
{
private:

protected:
typedef TCells::iterator base;
using base::operator ->;

public:
        CCell(const base& it);

CCell&  operator = (const TString& str);
CCell&  operator = (const TSharedString& str);
};

#endif

