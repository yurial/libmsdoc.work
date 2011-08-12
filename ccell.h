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

CCell&  operator = (const TString& string);
CCell&  operator = (const TSharedString& sharedstring);
CCell&  operator = (const TFormula& formula);
CCell&  operator = (const int value);
CCell&  operator = (const double value);
};

#endif

