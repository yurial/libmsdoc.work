#ifndef CSPREADSHEETOBJECTH
#define CSPREADSHEETOBJECTH

#include <map>

class CSpreadSheetObject;
typedef CSpreadSheetObject TSpreadSheetObject;

#include "cstring.h"
#include "cbaserelationshipobject.h"
#include "cspreadsheets.h"
#include "crow.h"

class CSpreadSheetObject:
    public TBaseRelationShipObject
{
private:
/* you can't do that */
CSpreadSheetObject& operator = (const CSpreadSheetObject&);

protected:
TRows           m_rows;
TString         m_dir;

const TString   filename() const;
ECONTENTTYPE    type() const;
public:
                CSpreadSheetObject(const TString& dir, TRelationShips& relationships);
                CSpreadSheetObject(const CSpreadSheetObject& origin);
                ~CSpreadSheetObject();

TRow            operator [] (int index);

int             save(TZip& archive, TContent& content) const;
};

#endif

