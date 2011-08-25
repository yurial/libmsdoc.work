#include "cborders.h"

#ifndef CBORDERH
#define CBORDERH

class CBorder;
typedef CBorder TBorder;

class ITBorderFromTCellXFObject
{
public:
virtual int id() const = 0;
virtual bool IsSet() const = 0 ;
};

class CBorder:
    public ITBorderFromTCellXFObject,
    protected TBordersContainer::iterator
{
protected:
typedef TBordersContainer::iterator base;
using base::operator ->;

ITBordersFromTBorder*    m_borders;

/* ITBorderFromTCellXFObject */
int     id() const;
bool    IsSet() const;

void    Link() const;
void    UnLink() const;

public:
        CBorder();
        CBorder(ITBordersFromTBorder& borders, const TBordersContainer::iterator& it);
        CBorder(const CBorder& origin);
        ~CBorder();

CBorder&operator =  (const CBorder& rvalue);
bool    operator <  (const CBorder& rvalue) const;
};

#endif

