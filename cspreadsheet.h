#ifndef CSPREADSHEETH
#define CSPREADSHEETH

#include <list>

class CSpreadSheet;
typedef CSpreadSheet TSpreadSheet;

#include "ccontent.h"
#include "cspreadsheets.h"
#include "cspreadsheetobject.h"
#include "crow.h"

class CSpreadSheet:
    public std::list<CSpreadSheetObject>::iterator
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

                operator IRelationShipObject& ();
};

#endif

