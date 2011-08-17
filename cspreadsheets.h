#ifndef CSPREADSHEETSH
#define CSPREADSHEETSH

#include <list>

class CSpreadSheets;
typedef CSpreadSheets TSpreadSheets;

#include "cspreadsheet.h"
#include "cspreadsheetobject.h"
#include "ccontent.h"
#include "crelationships.h"

class ITSpreadSheetsFromTWorkBook
{
public:
virtual int save(TZip& archive, TContent& content) const = 0;
};

class CSpreadSheets:
    public ITSpreadSheetsFromTWorkBook,
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

/*ITSpreadSheetsFromTWorkBook*/
int             save(TZip& archive, TContent& content) const;

public:
                CSpreadSheets(const TString& dir, TRelationShips& relationships);
                ~CSpreadSheets();

TSpreadSheet    insert();
};

#endif

