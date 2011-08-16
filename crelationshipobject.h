#ifndef CRELATIONSHIPOBJECTH
#define CRELATIONSHIPOBJECTH

class CRelationShipObject;
typedef CRelationShipObject TRelationShipObject;

#include "irelationobject.h"

class CRelationShipObject
{
protected:
int                     m_rid;
const IRelationObject*  m_object;

public:
                CRelationShipObject(const IRelationObject* object, int id);
int             rid() const;
ECONTENTTYPE    type() const;
const TString   filename() const;

CRelationShipObject& operator -- ();
};

#endif

