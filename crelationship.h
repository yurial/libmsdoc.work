#ifndef CRELATIONSHIPH
#define CRELATIONSHIPH

#include <list>

class CRelationShip;
typedef CRelationShip TRelationShip;

#include "crelationshipobject.h"

class CRelationShip:
    public std::list<TRelationShipObject>::iterator
{
protected:
typedef std::list<TRelationShipObject> list;
typedef std::list<TRelationShipObject>::iterator base;

public:
                CRelationShip(const base& it);
int             rid() const;
const TString   filename() const;
ECONTENTTYPE    type() const;
};

#endif

