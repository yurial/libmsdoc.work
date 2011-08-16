#ifndef CWORKBOOKLISTOBJECTH
#define CWORKBOOKLISTOBJECTH

class CWorkBookListObject;
typedef CWorkBookListObject TWorkBookListObject;

#include "cstring.h"
#include "irelationshipobject.h"

class CWorkBookListObject
{
protected:
IRelationShipObject*    m_object;
TString                 m_name;

public:
                        CWorkBookListObject(IRelationShipObject* object, const TString& name);
const TString&          name() const;
      TString&          name();
      int               rid() const;
};

#endif

