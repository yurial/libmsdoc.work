#include "cspreadsheets.h"

CSpreadSheets::CSpreadSheets()
{
}

CSpreadSheets::~CSpreadSheets()
{
}

TSpreadSheet CSpreadSheets::add()
{
return insert( end(), TSpreadSheetObject() );
}

TSpreadSheet CSpreadSheets::add(const TString& name)
{
return insert( end(), TSpreadSheetObject( name ) );
}

