#ifndef CSPREADSHEETSH
#define CSPREADSHEETSH

#include <list>

class CSpreadSheets;
typedef CSpreadSheets TSpreadSheets;

#include "cspreadsheet.h"

class CSpreadSheets:
    protected std::list<TSpreadSheetObject>
{
protected:
typedef std::list<TSpreadSheetObject> base;

public:
                CSpreadSheets();
                ~CSpreadSheets();

TSpreadSheet    add();
TSpreadSheet    add(const TString& name);
void            erase(TSpreadSheet& spreadsheet);
using           base::size;
};

#endif

