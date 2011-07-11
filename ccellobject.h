#ifndef CCELLOBJECTH
#define CCELLOBJECTH

class CCellObject;
typedef CCellObject TCellObject;

#include "csharedstring.h"

class CCellObject
{
private:

protected:
TSharedString*  m_shastr;
TString*        m_str;

public:
                CCellObject();
                ~CCellObject();

CCellObject&    operator = (const TString& str);
CCellObject&    operator = (const TSharedString& str);
};

#endif

