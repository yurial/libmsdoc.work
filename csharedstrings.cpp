#include <sstream>
#include "csharedstrings.h"

CSharedStrings::CSharedStrings(const TString& dir, TRelationShips& relationships):
    m_dir( dir ), m_relationships( relationships ), m_relationship( relationships.insert( this ) )
{
}

int CSharedStrings::save(TZip& archive, TContent& content) const
{
content.insert( filename(), ECT_SHARED_STRING_TABLE );
std::stringstream sharedstrings;
sharedstrings << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
sharedstrings << "<sst xmlns=\"http://schemas.openxmlformats.org/spreadsheetml/2006/main\">\n";

base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    sharedstrings << "<si><t>" << it->first << "</t></si>\n";
    }
sharedstrings << "</sst>";
archive.add_file( filename(), sharedstrings.str() );
return 0;
}

TSharedString CSharedStrings::insert(const TString& string)
{
std::pair<base::iterator,bool> result = base::insert( std::make_pair( TSharedStringObject( string ), size() ) );
return result.first;
}

void CSharedStrings::erase(TSharedString& sharedstring)
{
base::iterator it = sharedstring;
base::iterator end = base::end();
while ( ++it != end )
    {
    --(it->second);
    }
base::erase( sharedstring );
}

const TString CSharedStrings::filename() const
{
return m_dir + "/sharedStrings.xml";
}

ERELTYPE CSharedStrings::type() const
{
return ERT_SHAREDSTRINGS;
}

int CSharedStrings::rid() const
{
return m_relationship.rid();
}

