#include "crelationship.h"

CRelationShip::CRelationShip(const base& it):
    base( it )
{
}

int CRelationShip::rid() const
{
return (*this)->rid();
}

const TString CRelationShip::filename() const
{
return (*this)->filename();
}

ECONTENTTYPE CRelationShip::type() const
{
return (*this)->type();
}

