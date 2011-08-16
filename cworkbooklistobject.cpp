#include "cworkbooklistobject.h"

CWorkBookListObject::CWorkBookListObject(IRelationShipObject* object, const TString& name):
    m_object( object ), m_name( name )
{
}

const TString& CWorkBookListObject::name() const
{
return m_name;
}

TString& CWorkBookListObject::name()
{
return m_name;
}

int CWorkBookListObject::rid() const
{
return m_object->rid();
}

