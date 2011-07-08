#ifndef CSPREADSHEETOBJECTH
#define CSPREADSHEETOBJECTH

class CSpreadSheetObject;
typedef CSpreadSheetObject TSpreadSheetObject;

#include "cstring.h"

class CSpreadSheetObject
{
protected:
TString     m_name;

public:
            CSpreadSheetObject();
            CSpreadSheetObject(const TString& name);
TString&    name();
};

#endif

