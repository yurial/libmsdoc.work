#ifndef CSHAREDSTRINGOBJECTH
#define CSHAREDSTRINGOBJECTH

#include "cstring.h"
#include "cformula.h"

class CSharedStringObject;
typedef CSharedStringObject TSharedStringObject;

class ITSharedStringObjectFromTSharedStrings
{
protected:
int     m_id;

public:
        ITSharedStringObjectFromTSharedStrings();
        ITSharedStringObjectFromTSharedStrings(const ITSharedStringObjectFromTSharedStrings& origin);
        
void    SetId(int id);
int     GetId() const;
void    operator ++ ();
void    operator -- ();

virtual TString save() const = 0;
};

class ITSharedStringObjectFromTSharedString
{
protected:
mutable int m_links;

public:
            ITSharedStringObjectFromTSharedString();
            ITSharedStringObjectFromTSharedString(const ITSharedStringObjectFromTSharedString& origin);

void        Link() const;
int         UnLink() const;

virtual int id() const = 0;
};

class CSharedStringObject:
    public ITSharedStringObjectFromTSharedStrings,
    public ITSharedStringObjectFromTSharedString,
    protected TString
{
private:
CSharedStringObject& operator = (const CSharedStringObject&);

protected:
using std::string::operator =;

/* ITSharedStringObjectFromTSharedStrings */
TString save() const;

/* ITSharedStringObjectFromTSharedString */
int     id() const;

public:
        CSharedStringObject(const TString& string);
        CSharedStringObject(const CSharedStringObject& origin);

bool    operator <  (const CSharedStringObject& rvalue) const;
};

#endif

