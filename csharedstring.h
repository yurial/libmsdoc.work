#ifndef CSHAREDSTRINGH
#define CSHAREDSTRINGH

class CSharedString;
typedef CSharedString TSharedString;

#include "csharedstrings.h"
#include "csharedstringobject.h"

class ITSharedStringFromTCellObject
{
public:
virtual int id() const = 0;
};

class CSharedString:
    public ITSharedStringFromTCellObject,
    public TSharedStringsContainer::iterator
{
private:
/* you can't do that */
CSharedString&  operator = (const CSharedString&);

protected:
typedef TSharedStringsContainer::iterator base;
using   base::operator *;

ITSharedStringsFromTSharedString&   m_sharedstrings;

/*ITSharedStringFromTCellObject*/
int             id() const;

public:
                CSharedString(ITSharedStringsFromTSharedString& sharedstrings, const base& it);
                CSharedString(const CSharedString& origin);
                ~CSharedString();
};

#endif

