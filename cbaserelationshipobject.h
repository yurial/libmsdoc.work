#ifndef CBASERELATIONSHIPOBJECTH
#define CBASERELATIONSHIPOBJECTH

class CBaseRelationShipObject;
typedef CBaseRelationShipObject TBaseRelationShipObject;

#include "cstring.h"
#include "ccontent.h"
#include "irelationshipobject.h"
#include "crelationships.h"

class CBaseRelationShipObject:
    public IRelationShipObject
{
protected:
TRelationShips& m_relationships;
TRelationShip   m_relationship;

                CBaseRelationShipObject(TRelationShips& relationships);
                CBaseRelationShipObject(const CBaseRelationShipObject& origin);
                ~CBaseRelationShipObject();
public:
virtual const TString   filename() const = 0;
virtual ECONTENTTYPE    type() const = 0;
virtual int             rid() const;
};

#endif

