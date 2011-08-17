#ifndef CDATEH
#define CDATEH

#include "cstring.h"

class CDate;
typedef CDate TDate;

class CDate
{
protected:
int         m_uts;

public:
            CDate(int uts);
TString     c_str() const;
};

#endif

