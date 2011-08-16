#ifndef CSHAREDSTRINGSH
#define CSHAREDSTRINGSH

#include <map>

class CSharedStrings;
typedef CSharedStrings TSharedStrings;

#include "czip.h"
#include "ccontent.h"
#include "cbaserelationshipobject.h"
#include "csharedstring.h"

class ITSharedStringsFromTWorkBook
{
public:
virtual int save(TZip& archive, TContent& content) const = 0;
};

class CSharedStrings:
    public ITSharedStringsFromTWorkBook,
    public TBaseRelationShipObject,
    protected std::map<TSharedStringObject,int>
{
private:
/* you can't do that */
                CSharedStrings(const CSharedStrings&);
CSharedStrings& operator = (const CSharedStrings&);

protected:
typedef std::map<TSharedStringObject,int> base;

TString         m_dir;

/*TBaseRelationShipObject*/
const TString   filename() const;
ECONTENTTYPE    type() const;
/*ITSharedStringsFromTWorkBook*/
int             save(TZip& archive, TContent& content) const;

public:
                CSharedStrings(const TString& dir, TRelationShips& relationships);

TSharedString   insert(const TString& string);
void            erase(TSharedString& sharedstring);
};

#endif

