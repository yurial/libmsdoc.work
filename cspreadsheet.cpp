#include "cspreadsheet.h"

CSpreadSheet::CSpreadSheet(const std::list<CSpreadSheetObject>::iterator& it):
    base( it )
{
}

TString& CSpreadSheet::name()
{
return (*this)->name();
}

