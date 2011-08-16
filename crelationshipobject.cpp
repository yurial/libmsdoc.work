#include "crelationshipobject.h"

CRelationShipObject::CRelationShipObject(const IRelationObject* object, int rid)
{
m_object = object;
m_rid = rid;
}

int CRelationShipObject::rid() const
{
return m_rid;
}

ECONTENTTYPE CRelationShipObject::type() const
{
return m_object->type();
}

const TString CRelationShipObject::filename() const
{
return m_object->filename();
}

CRelationShipObject& CRelationShipObject::operator -- ()
{
--m_rid;
return *this;
}

