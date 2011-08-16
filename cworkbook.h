#ifndef CWORKBOOKH
#define CWORKBOOKH

class CWorkBook;
typedef CWorkBook TWorkBook;

#include "czip.h"
#include "cbaserelationshipobject.h"
#include "cworkbooklist.h"
#include "cworkbooklistobject.h"
#include "cspreadsheets.h"
#include "csharedstrings.h"
#include "ccontent.h"

class ITWorkBookFromTDocXLSX
{
public:
virtual int save(TZip& archive, TContent& content) const = 0;
};

class CWorkBook:
    public ITWorkBookFromTDocXLSX,
    public TBaseRelationShipObject,
    public std::list<TWorkBookListObject>
{
private:
CWorkBook(const CWorkBook&);
CWorkBook& operator = (const CWorkBook&);

protected:
typedef std::list<TWorkBookListObject> base;

TString         m_dir;

/*TBaseRelationShipObject*/
const TString   filename() const;
ECONTENTTYPE    type() const;
/*ITWorkBookFromTDocXLSX*/
int             save(TZip& archive, TContent& content) const;

public:
TSpreadSheets   m_spreadsheets;
TSharedStrings  m_sharedstrings;
//TStyleSheet     m_stylesheet;

public:
                CWorkBook(const TString& dir, TRelationShips& relationships);
TWorkBookList   insert(IRelationShipObject& list, const TString& name);
void            erase(TWorkBookList& list);
void            swap(TWorkBookList& l, TWorkBookList& r);
};

#endif

