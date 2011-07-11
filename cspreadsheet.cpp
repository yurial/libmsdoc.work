#include "cspreadsheet.h"

CSpreadSheet::CSpreadSheet(const std::list<CSpreadSheetObject>::iterator& it):
    base( it )
{
}

TRow CSpreadSheet::operator [] (int index)
{
return (*this)->operator [] ( index );
}

TString& CSpreadSheet::name()
{
return (*this)->name();
}

