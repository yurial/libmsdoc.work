#ifndef CNUMFMTH
#define CNUMFMTH

class CNumFmt;
typedef CNumFmt TNumFmt;

#include "cnumfmts.h"
#include "cnumfmtobject.h"

class ITNumFmtFromTCellXFObject
{
public:
virtual int     id() const = 0;
virtual bool    IsSet() const = 0;
};

class CNumFmt:
    public ITNumFmtFromTCellXFObject,
    protected TNumFmtsContainer::iterator
{
protected:
typedef TNumFmtsContainer::iterator base;
using base::operator ->;

ITNumFmtsFromTNumFmt*   m_numfmts;

/* ITNumFmtFromTCellXFObject */
int         id() const;
bool        IsSet() const;

void        Link() const;
void        UnLink() const;

CNumFmt&    operator |= (const CNumFmt& rvalue);

public:
            CNumFmt();
            CNumFmt(ITNumFmtsFromTNumFmt& numfmts, const base& it);
            CNumFmt(const CNumFmt& origin);
            ~CNumFmt();

CNumFmt&    operator =  (const CNumFmt& rvalue);
bool        operator <  (const CNumFmt& rvalue) const;
};

#endif

