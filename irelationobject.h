#ifndef IRELATIONOBJECTH
#define IRELATIONOBJECTH

#include "cstring.h"
#include "ccontent.h"

class IRelationObject
{
public:
virtual const TString   filename() const = 0;
virtual ECONTENTTYPE    type() const = 0;
virtual int             rid() const = 0;
};

#endif

