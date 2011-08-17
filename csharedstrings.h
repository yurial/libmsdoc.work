#ifndef CSHAREDSTRINGSH
#define CSHAREDSTRINGSH

#include <set>

class CSharedStrings;
typedef CSharedStrings TSharedStrings;

#include "czip.h"
#include "ccontent.h"
#include "cbaserelationshipobject.h"
#include "csharedstringobject.h"
typedef std::set<TSharedStringObject> TSharedStringsContainer;

class ITSharedStringsFromTWorkBook
{
public:
virtual int save(TZip& archive, TContent& content) const = 0;
};

class ITSharedStringsFromTSharedString
{
public:
virtual void erase(TSharedStringsContainer::iterator& sharedstring) = 0;
};

#include "csharedstring.h"

class CSharedStrings:
    public ITSharedStringsFromTWorkBook,
    public ITSharedStringsFromTSharedString,
    public TBaseRelationShipObject,
    protected TSharedStringsContainer
{
private:
/* you can't do that */
                CSharedStrings(const CSharedStrings&);
CSharedStrings& operator = (const CSharedStrings&);

protected:
typedef TSharedStringsContainer base;

TString         m_dir;

/* TBaseRelationShipObject */
const TString   filename() const;
ECONTENTTYPE    type() const;
/* ITSharedStringsFromTWorkBook */
int             save(TZip& archive, TContent& content) const;
/*  ITSharedStringsFromTSharedString */
void            erase(base::iterator& sharedstring);

public:
                CSharedStrings(const TString& dir, TRelationShips& relationships);
TSharedString   insert(const TString& string);
};

#endif

