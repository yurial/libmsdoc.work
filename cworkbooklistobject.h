#ifndef CWORKBOOKLISTOBJECTH
#define CWORKBOOKLISTOBJECTH

class CWorkBookListObject;
typedef CWorkBookListObject TWorkBookListObject;

#include "cstring.h"
#include "iworkbooklist.h"

class CWorkBookListObject
{
protected:
IWorkBookList*  m_object;
TString         m_name;

public:
                CWorkBookListObject(IWorkBookList* object, const TString& name);

const TString&  name() const;
      TString&  name();

      int       rid() const;
};

#endif

