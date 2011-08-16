#ifndef CSPREADSHEETOBJECTH
#define CSPREADSHEETOBJECTH

#include <map>

class CSpreadSheetObject;
typedef CSpreadSheetObject TSpreadSheetObject;

#include "cstring.h"
#include "crelationships.h"
#include "iworkbooklist.h"
#include "cspreadsheets.h"
#include "crow.h"

class CSpreadSheetObject:
    public IRelationObject,
    public IWorkBookList
{
private:
/* you can't do that */
CSpreadSheetObject& operator = (const CSpreadSheetObject&);

protected:
TRelationShips& m_relationships;
TRelationShip   m_relationship;
TRows           m_rows;
TString         m_dir;

public:
                CSpreadSheetObject(const TString& dir, TRelationShips& relationships);
                CSpreadSheetObject(const CSpreadSheetObject& origin);
                ~CSpreadSheetObject();

TRow            operator [] (int index);

int             save(TZip& archive, TContent& content) const;

const TString   filename() const;
ECONTENTTYPE    type() const;
int             rid() const;
};

#endif

