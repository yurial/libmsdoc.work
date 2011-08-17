#include <sstream>
#include "cstylesheet.h"

CStyleSheet::CStyleSheet(const TString& dir, TRelationShips& relationships):
    TBaseRelationShipObject( relationships ), m_dir( dir )
{
}

const TString CStyleSheet::filename() const
{
return m_dir + "/styles.xml";
}

ECONTENTTYPE CStyleSheet::type() const
{
return ECT_STYLES;
}

int CStyleSheet::save(TZip& archive, TContent& content) const
{
content.insert( filename(), type() );
std::stringstream stylesheet;
stylesheet << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
stylesheet << "<stylesheet xmlns=\"" << g_contenttypes[ type() ].m_namespace << "\">\n";
stylesheet << "</stylesheet>";
archive.add_file( filename(), stylesheet.str() );
return 0;
}

