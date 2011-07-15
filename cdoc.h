#ifndef CDOCH
#define CDOCH

class CDoc;
typedef CDoc TDoc;

#include "crelationships.h"

class CDoc
{
protected:
TRelationShips  m_relationships;

public:
virtual int save(const TString& filename) const = 0;
};

#endif

