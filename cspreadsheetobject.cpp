#include "cspreadsheetobject.h"

CSpreadSheetObject::CSpreadSheetObject()
{
}

CSpreadSheetObject::CSpreadSheetObject(const TString& name):
    m_name( name )
{
}

TString& CSpreadSheetObject::name()
{
return m_name;
}

