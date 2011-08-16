#ifndef CRELATIONSHIPSH
#define CRELATIONSHIPSH

#include <list>

class CRelationShips;
typedef CRelationShips TRelationShips;

#include "czip.h"
#include "ccontent.h"
#include "crelationshipobject.h"
#include "crelationship.h"

class CRelationShips:
    protected std::list<TRelationShipObject>
{
protected:
typedef std::list<TRelationShipObject> base;

public:
TRelationShip   insert(const IRelationObject* object);
int             save(TZip& archive, const TString& filename) const;
void            erase(TRelationShip& relationship);
};

#endif

