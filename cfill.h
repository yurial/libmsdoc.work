#include "cfills.h"

#ifndef CFILLH
#define CFILLH

class CFill;
typedef CFill TFill;

class ITFillFromTCellXFObject
{
public:
virtual int id() const = 0;
virtual bool IsSet() const = 0;
};

class CFill:
    public ITFillFromTCellXFObject,
    protected TFillsContainer::iterator
{
protected:
typedef TFillsContainer::iterator base;
using base::operator ->;

ITFillsFromTFill*   m_fills;

/* ITFillFromTFills */
int     id() const;
bool    IsSet() const;

void    Link() const;
void    UnLink() const;

public:
        CFill();
        CFill(ITFillsFromTFill& fills, const TFillsContainer::iterator& it);
        CFill(const CFill& origin);
        ~CFill();

CFill&  operator =  (const CFill& rvalue);
bool    operator <  (const CFill& rvalue) const;
};

#endif

