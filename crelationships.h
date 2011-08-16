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
    protected std::list<SRelationShipObject>
{
protected:
typedef std::list<SRelationShipObject> base;

public:
TRelationShip   insert(const IRelationShipObject* object);
int             save(TZip& archive, const TString& filename) const;
void            erase(TRelationShip& relationship);
};

#endif

