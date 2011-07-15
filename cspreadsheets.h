#ifndef CSPREADSHEETSH
#define CSPREADSHEETSH

#include <list>

class CSpreadSheets;
typedef CSpreadSheets TSpreadSheets;

#include "cspreadsheet.h"
#include "cspreadsheetobject.h"
#include "ccontent.h"
#include "crelationships.h"

class CSpreadSheets:
    protected std::list<TSpreadSheetObject>
{
private:
/* you can't do that */
                CSpreadSheets(const CSpreadSheets&);
CSpreadSheets&  operator = (const CSpreadSheets&);

protected:
typedef std::list<TSpreadSheetObject> base;
TString         m_dir;
TRelationShips& m_relationships;

public:
                CSpreadSheets(const TString& dir, TRelationShips& relationships);
                ~CSpreadSheets();
int             save(TZip& archive, TContent& content) const;

TSpreadSheet    insert();
void            erase(TSpreadSheet& spreadsheet);
using           base::size;
};

#endif

