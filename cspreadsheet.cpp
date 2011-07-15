#include "cspreadsheet.h"

CSpreadSheet::CSpreadSheet(const base& it):
    base( it )
{
}

TRow CSpreadSheet::operator [] (int index)
{
return (*this)->operator [] ( index );
}

CSpreadSheet::operator IWorkBookList& ()
{
return this->operator *();
}

