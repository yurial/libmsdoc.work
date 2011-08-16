#include <sstream>
#include "crelationships.h"

TRelationShip CRelationShips::insert(const IRelationShipObject* object)
{
return base::insert( base::end(), SRelationShipObject( object, base::size()+1 ) );
}

int CRelationShips::save(TZip& archive, const TString& filename) const
{
std::stringstream content;
content << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
content << "<Relationships xmlns=\"http://schemas.openxmlformats.org/package/2006/relationships\">\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (;it != end; ++it)
    {
    content << "<Relationship Id=\"rId" << it->rid() << "\" Type=\"" << g_contenttypes[it->type()].m_relationship << "\" Target=\"/" << it->filename() << "\"/>\n";
    }
content << "</Relationships>";
archive.add_file( filename, content.str() );
return 0;
}

void CRelationShips::erase(TRelationShip& relationship)
{
base::iterator it = relationship;
base::iterator end = base::end();
while (++it != end)
    {
    --(it->m_rid);
    }
base::erase( relationship );
}

