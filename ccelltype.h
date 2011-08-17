#ifndef CCELLTYPEH
#define CCELLTYPEH

enum ECELLTYPE
{
ECT_NONE,
ECT_BOOLEAN,
ECT_DATE,
ECT_ERROR,
ECT_IS,
ECT_NUMBER,
ECT_SHARED_STRING,
ECT_STR,
};

class CCellType;
typedef CCellType TCellType;

#include "cstring.h"

class CCellType
{
private:
ECELLTYPE   m_type;

protected:
            CCellType();
void        SetType(ECELLTYPE type);
TString     t() const;
};

#endif

