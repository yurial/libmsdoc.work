#include "ccelltype.h"

static const char* g_celltypes[] = {
    NULL,
    "b",
    "d",
    "e",
    "inlineStr",
    "n",
    "s",
    "str",
};

CCellType::CCellType()
{
}

void CCellType::SetType(ECELLTYPE type)
{
m_type = type;
}

TString CCellType::t() const
{
TString result;
if ( NULL == g_celltypes[m_type] )
    {
    return result;
    }
result += " t=\"";
result += g_celltypes[m_type];
result += '\"';
return result;
}

