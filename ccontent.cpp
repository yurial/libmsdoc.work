#include <sstream>
#include <map>
#include "ccontent.h"
#include "cinitializer.h"

SContentType CONTENT_TYPES[] = {
    { ECT_WORKBOOK,                         "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml",   "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument" },
    { ECT_WORKSHEET,                        "application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet" },
    { ECT_SHARED_STRING_TABLE,              "application/vnd.openxmlformats-officedocument.spreadsheetml.sharedStrings+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/sharedStrings" },
    { ECT_STYLES,                           "application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles" },
    { ECT_DRAWINGS,                         "application/vnd.openxmlformats-officedocument.drawing+xml", "http://schemas.openxmlformats.org/drawingml/2006/spreadsheetDrawing", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/drawing" },
    { ECT_CHARTSHEET,                       "application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chartsheet" },
    { ECT_EXTERNAL_WORKBOOK_REFERENCE,      "application/vnd.openxmlformats-officedocument.spreadsheetml.externalLink+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLink" },
    { ECT_CALCULATION_CHAIN,                "application/vnd.openxmlformats-officedocument.spreadsheetml.calcChain+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/calcChain" },
    { ECT_COMMENTS,                         "application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/comments" },
    { ECT_CONNECTIONS,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.connections+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/connections" },
    { ECT_CUSTOM_PROPERTY,                  "application/xml", "", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/customProperty" },
    { ECT_CUSTOM_XML_MAPPINGS,              "application/xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/xmlMaps" },
    { ECT_DIALOGSHEET,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.dialogsheet+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/dialogsheet" },
    { ECT_METADATA,                         "application/vnd.openxmlformats-officedocument.spreadsheetml.sheetMetadata+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/sheetMetadata" },
    { ECT_QUERY_TABLE,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.queryTable+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/queryTable" },
    { ECT_PIVOT_TABLE,                      "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotTable+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/pivotTable" },
    { ECT_PIVOT_TABLE_CACHE_DEFINITION,     "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotCacheDefinition+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/pivotCacheDefinition" },
    { ECT_PIVOT_TABLE_CACHE_REORDS,         "application/vnd.openxmlformats-officedocument.spreadsheetml.pivotCacheRecords+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/pivotCacheRecords" },
    { ECT_SHARED_WORKBOOK_USER_DATA,        "application/vnd.openxmlformats-officedocument.spreadsheetml.userNames+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/usernames" },
    { ECT_SHARED_WORKBOOK_REVISION_HEADERS, "application/vnd.openxmlformats-officedocument.spreadsheetml.revisionHeaders+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/revisionHeaders" },
    { ECT_SHARED_WORKBOOK_REVISION_LOG,     "application/vnd.openxmlformats-officedocument.spreadsheetml.revisionLog+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/revisionLog" },
    { ECT_SINGLE_CELL_TABLE_DEFINITIONS,    "application/vnd.openxmlformats-officedocument.spreadsheetml.tableSingleCells+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/tableSingleCells" },
    { ECT_TABLE_DEFINITION,                 "application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/table" },
    { ECT_VOLATILE_DEPENDENCIES,            "application/vnd.openxmlformats-officedocument.spreadsheetml.volatileDependencies+xml", "http://schemas.openxmlformats.org/spreadsheetml/2006/main", "http://schemas.openxmlformats.org/officeDocument/2006/relationships/volatileDependencies" },
};

TContentTypes g_contenttypes;

static void content_init_f()
{
for (unsigned int index = 0; index < sizeof(CONTENT_TYPES)/sizeof(SContentType); ++index)
    {
    g_contenttypes.insert( std::make_pair( CONTENT_TYPES[index].m_id, CONTENT_TYPES[index] ) );
    }
}

static CInitializer content_init( content_init_f );

SContentObject::SContentObject(const TString& filename, ECONTENTTYPE type):
    m_filename( filename ), m_type( type )
{
}

void CContent::insert(const TString& filename, ECONTENTTYPE type)
{
base::push_back( SContentObject( filename, type ) );
}

int CContent::save(TZip& archive) const
{
std::stringstream content;
content << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
content << "<Types xmlns=\"http://schemas.openxmlformats.org/package/2006/content-types\">\n";
content << "<Default Extension=\"rels\" ContentType=\"application/vnd.openxmlformats-package.relationships+xml\"/>\n";
content << "<Default Extension=\"xml\" ContentType=\"application/xml\"/>\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    content << "<Override PartName=\"/" << it->m_filename << '"';
    content << " ContentType=\"" << g_contenttypes[it->m_type].m_type << "\"/>\n";
    }
content << "</Types>\n";
int ret = archive.add_file( "[Content_Types].xml", content.str() );
//TODO: ret
return ret;
}

