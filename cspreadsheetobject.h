#ifndef CSPREADSHEETOBJECTH
#define CSPREADSHEETOBJECTH

#include <map>

class CSpreadSheetObject;
typedef CSpreadSheetObject TSpreadSheetObject;

#include "cstring.h"
#include "crow.h"

class CSpreadSheetObject
{
private:
/* you can't do that */
CSpreadSheetObject& operator = (const CSpreadSheetObject&);

protected:
TString     m_name;
TRows       m_rows;

public:
            CSpreadSheetObject();
            CSpreadSheetObject(const TString& name);
TRow        operator [] (int index);
TString&    name();
};

#endif

