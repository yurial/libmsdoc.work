#include "ccell.h"

CCell::CCell(const base& it):
    base( it )
{
}

CCell& CCell::operator = (const TString& string)
{
(*this)->second.operator = ( string );
return *this;
}

CCell& CCell::operator = (const TSharedString& sharedstring)
{
(*this)->second.operator = ( sharedstring );
return *this;
}

CCell& CCell::operator = (const TFormula& formula)
{
(*this)->second.operator = ( formula );
return *this;
}

CCell& CCell::operator = (const TDate& date)
{
(*this)->second.operator = ( date );
return *this;
}

CCell& CCell::operator = (const int value)
{
(*this)->second.operator = ( value );
return *this;
}

CCell& CCell::operator = (const double value)
{
(*this)->second.operator = ( value );
return *this;
}

CCell& CCell::operator = (const TCellXF& cellxf)
{
(*this)->second.operator = ( cellxf );
return *this;
}

TString CCell::cell() const
{
return (*this)->second.cell();
}

