#include "ccell.h"

CCell::CCell(const base& it):
    base( it )
{
}

CCell& CCell::operator = (const TString& str)
{
(*this)->second.operator = ( str );
return *this;
}

CCell& CCell::operator = (const TFormula& frm)
{
(*this)->second.operator = ( frm );
return *this;
}

CCell& CCell::operator = (const TSharedString& str)
{
(*this)->second.operator = ( str );
return *this;
}

