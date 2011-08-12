#include <sstream>
#include "ccontent.h"

TString g_contenttypes[] = {
"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml",
"application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml",
"application/vnd.openxmlformats-officedocument.spreadsheetml.sharedStrings+xml",
"application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"
};

SContent::SContent(const TString& filename, ECONTENTTYPE type):
    m_filename( filename ), m_type( type )
{
}

void CContent::insert(const TString& filename, ECONTENTTYPE type)
{
base::push_back( SContent( filename, type ) );
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
    content << " ContentType=\"" << g_contenttypes[it->m_type] << "\"/>\n";
    }
content << "</Types>\n";
int ret = archive.add_file( "[Content_Types].xml", content.str() );
//TODO: ret
return ret;
}

