#ifndef CSHAREDSTRINGSH
#define CSHAREDSTRINGSH

#include <map>

class CSharedStrings;
typedef CSharedStrings TSharedStrings;

#include "czip.h"
#include "ccontent.h"
#include "crelationships.h"
#include "csharedstring.h"

class CSharedStrings:
    public IRelationObject,
    protected std::map<TSharedStringObject,int>
{
private:
/* you can't do that */
                CSharedStrings(const CSharedStrings&);
CSharedStrings& operator = (const CSharedStrings&);

protected:
typedef std::map<TSharedStringObject,int> base;

TString         m_dir;
TRelationShips& m_relationships;
TRelationShip   m_relationship;

const TString   filename() const;
ERELTYPE        type() const;
int             rid() const;

public:
                CSharedStrings(const TString& dir, TRelationShips& relationships);
int             save(TZip& archive, TContent& content) const;

TSharedString   insert(const TString& string);
void            erase(TSharedString& sharedstring);
using           base::size;
};

#endif

