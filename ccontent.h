#ifndef CCONTENTTYPEH
#define CCONTENTTYPEH

#include <list>

class CContent;
typedef CContent TContent;

#include "cstring.h"
#include "czip.h"

enum ECONTENTTYPE
{
ECT_WORKBOOK,
ECT_SPREADSHEET,
ECT_SHAREDSTRINGS,
ECT_STYLES
};

struct SContent
{
TString         m_filename;
ECONTENTTYPE    m_type;
                SContent(const TString& filename, ECONTENTTYPE type);
};

class CContent:
    protected std::list<SContent>
{
protected:
typedef std::list<SContent> base;

public:
void    insert(const TString& filename, ECONTENTTYPE type);
int     save(TZip& archive) const;
};

#endif

