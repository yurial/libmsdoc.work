#ifndef IRELATIONSHIPOBJECTH
#define IRELATIONSHIPOBJECTH

#include "cstring.h"
#include "ccontent.h"

class IRelationShipObject
{
public:
virtual const TString   filename() const = 0;
virtual ECONTENTTYPE    type() const = 0;
virtual int             rid() const = 0;
};

#endif

