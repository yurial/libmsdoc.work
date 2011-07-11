#include "cspreadsheetobject.h"

CSpreadSheetObject::CSpreadSheetObject()
{
}

CSpreadSheetObject::CSpreadSheetObject(const TString& name):
    m_name( name )
{
}

TRow CSpreadSheetObject::operator [] (int index)
{
std::pair<TRows::iterator,bool> row = m_rows.insert( std::make_pair( index, TRowObject() ) );
return row.first;
}

TString& CSpreadSheetObject::name()
{
return m_name;
}

