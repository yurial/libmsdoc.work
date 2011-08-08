#ifndef CWORKBOOKH
#define CWORKBOOKH

class CWorkBook;
typedef CWorkBook TWorkBook;

#include "czip.h"
#include "irelationobject.h"
#include "cworkbooklist.h"
#include "cworkbooklistobject.h"
#include "cspreadsheets.h"
#include "csharedstrings.h"
#include "ccontent.h"
#include "crelationships.h"

class CWorkBook:
    public IRelationObject,
    public std::list<TWorkBookListObject>
{
private:
CWorkBook(const CWorkBook&);
CWorkBook& operator = (const CWorkBook&);

protected:
typedef std::list<TWorkBookListObject> base;

TString         m_dir;
TRelationShip   m_relationship;
TRelationShips  m_relationships;

public:
TSpreadSheets   m_spreadsheets;
TSharedStrings  m_sharedstrings;

public:
                CWorkBook(const TString& dir, TRelationShips& relationships);
TWorkBookList   begin();
TWorkBookList   end();
TWorkBookList   insert(IWorkBookList& list, const TString& name);
void            erase(TWorkBookList& list);
void            swap(TWorkBookList& l, TWorkBookList& r);

int             save(TZip& archive, TContent& content) const;

const TString   filename() const;
ERELTYPE        type() const;
int             rid() const;
};

#endif

