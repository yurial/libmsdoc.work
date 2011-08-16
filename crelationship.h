#ifndef CRELATIONSHIPH
#define CRELATIONSHIPH

#include <list>

class CRelationShip;
typedef CRelationShip TRelationShip;

#include "crelationshipobject.h"

class CRelationShip:
    public std::list<SRelationShipObject>::iterator
{
protected:
typedef std::list<SRelationShipObject> list;
typedef std::list<SRelationShipObject>::iterator base;

public:
                CRelationShip(const base& it);
int             rid() const;
const TString   filename() const;
ECONTENTTYPE    type() const;
};

#endif

