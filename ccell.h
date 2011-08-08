#ifndef CCELLH
#define CCELLH

class CCell;
typedef CCell TCell;

#include "csharedstring.h"
#include "ccellobject.h"
#include "cformula.h"

class CCell:
    public TCells::iterator
{
private:

protected:
typedef TCells::iterator base;
using base::operator ->;

public:
        CCell(const base& it);

CCell&  operator = (const TString& str);
CCell&  operator = (const TFormula& frm);
CCell&  operator = (const TSharedString& str);
};

#endif

