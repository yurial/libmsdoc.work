#ifndef CCONTENTTYPEH
#define CCONTENTTYPEH

#include <map>
#include <list>

class CContent;
typedef CContent TContent;

#include "cstring.h"
#include "czip.h"

enum ECONTENTTYPE
{
ECT_WORKBOOK,                           //12.3.23
ECT_WORKSHEET,                          //12.3.24
ECT_SHARED_STRING_TABLE,                //12.3.15
ECT_STYLES,                             //12.3.20
ECT_DRAWINGS,                           //12.3.8
ECT_CHARTSHEET,                         //12.3.2
ECT_EXTERNAL_WORKBOOK_REFERENCE,        //12.3.9
ECT_CALCULATION_CHAIN,                  //12.3.1
ECT_COMMENTS,                           //12.3.3
ECT_CONNECTIONS,                        //12.3.4
ECT_CUSTOM_PROPERTY,                    //12.4.5
ECT_CUSTOM_XML_MAPPINGS,                //12.3.6
ECT_DIALOGSHEET,                        //12.3.7
ECT_METADATA,                           //12.3.10
ECT_QUERY_TABLE,                        //12.3.14
ECT_PIVOT_TABLE,                        //12.3.11
ECT_PIVOT_TABLE_CACHE_DEFINITION,       //12.3.12
ECT_PIVOT_TABLE_CACHE_REORDS,           //12.3.13
ECT_SHARED_WORKBOOK_USER_DATA,          //12.3.18
ECT_SHARED_WORKBOOK_REVISION_HEADERS,   //12.3.16
ECT_SHARED_WORKBOOK_REVISION_LOG,       //12.3.17
ECT_SINGLE_CELL_TABLE_DEFINITIONS,      //12.3.19
ECT_TABLE_DEFINITION,                   //12.3.21
ECT_VOLATILE_DEPENDENCIES,              //12.3.22
};

struct SContentType
{
ECONTENTTYPE    m_id;
TString         m_type;
TString         m_namespace;
TString         m_relationship;
};

typedef std::map<ECONTENTTYPE,SContentType> TContentTypes;
extern TContentTypes g_contenttypes;

struct SContentObject
{
TString         m_filename;
ECONTENTTYPE    m_type;
                SContentObject(const TString& filename, ECONTENTTYPE type);
};

class CContent:
    protected std::list<SContentObject>
{
protected:
typedef std::list<SContentObject> base;

public:
void    insert(const TString& filename, ECONTENTTYPE type);
int     save(TZip& archive) const;
};

#endif

