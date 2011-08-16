#ifndef CSHAREDSTRINGH
#define CSHAREDSTRINGH

#include <map>

class CSharedString;
typedef CSharedString TSharedString;

#include "csharedstringobject.h"

class ITSharedStringFromTCellObject
{
public:
virtual int id() const = 0;
};

class CSharedString:
    public ITSharedStringFromTCellObject,
    public std::map<TSharedStringObject,int>::iterator
{
private:
/* you can't do that */
CSharedString&  operator = (const CSharedString&);

protected:
typedef std::map<TSharedStringObject,int>::iterator base;
using   base::operator ->;

/*ITSharedStringFromTCellObject*/
int             id() const;

public:
                CSharedString(const base& it);
};

#endif

