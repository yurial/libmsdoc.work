#ifndef CSPREADSHEETH
#define CSPREADSHEETH

#include <list>

class CSpreadSheet;
typedef CSpreadSheet TSpreadSheet;

#include "cspreadsheetobject.h"

class CSpreadSheet:
    protected std::list<CSpreadSheetObject>::iterator
{
private:
/* you can't do that */
CSpreadSheet&   operator = (const CSpreadSheet&);

protected:
typedef std::list<CSpreadSheetObject>::iterator base;
using base::operator ->;

public:
                CSpreadSheet(const base& it);

TRow            operator [] (int index);

TString&        name();
};

#endif

