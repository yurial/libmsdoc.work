#ifndef SRELATIONSHIPOBJECTH
#define SRELATIONSHIPOBJECTH

#include "irelationshipobject.h"

class SRelationShipObject
{
public:
int                         m_rid;
const IRelationShipObject*  m_object;

public:
                SRelationShipObject(const IRelationShipObject* object, int rid);
int             rid() const;
ECONTENTTYPE    type() const;
const TString   filename() const;
};

#endif

