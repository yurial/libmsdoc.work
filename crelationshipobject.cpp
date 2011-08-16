#include "crelationshipobject.h"

SRelationShipObject::SRelationShipObject(const IRelationShipObject* object, int rid)
{
m_object = object;
m_rid = rid;
}

int SRelationShipObject::rid() const
{
return m_rid;
}

ECONTENTTYPE SRelationShipObject::type() const
{
return m_object->type();
}

const TString SRelationShipObject::filename() const
{
return m_object->filename();
}

