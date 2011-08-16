#include "cbaserelationshipobject.h"

CBaseRelationShipObject::CBaseRelationShipObject(TRelationShips& relationships):
    m_relationships( relationships ), m_relationship( m_relationships.insert( this ) )
{
}

CBaseRelationShipObject::CBaseRelationShipObject(const CBaseRelationShipObject& origin):
    m_relationships( origin.m_relationships ), m_relationship( m_relationships.insert( this ) )
{
}

CBaseRelationShipObject::~CBaseRelationShipObject()
{
m_relationships.erase( m_relationship );
}

int CBaseRelationShipObject::rid() const
{
return m_relationship.rid();
}

