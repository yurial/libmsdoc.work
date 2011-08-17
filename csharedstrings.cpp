#include <sstream>
#include "csharedstrings.h"

CSharedStrings::CSharedStrings(const TString& dir, TRelationShips& relationships):
    TBaseRelationShipObject( relationships ), m_dir( dir )
{
}

int CSharedStrings::save(TZip& archive, TContent& content) const
{
content.insert( filename(), type() );
std::stringstream sharedstrings;
sharedstrings << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
sharedstrings << "<sst xmlns=\"http://schemas.openxmlformats.org/spreadsheetml/2006/main\">\n";

base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    sharedstrings << "<si><t>" << ((const ITSharedStringObjectFromTSharedStrings&)*it).save() << "</t></si>\n";
    }
sharedstrings << "</sst>";
archive.add_file( filename(), sharedstrings.str() );
return 0;
}

TSharedString CSharedStrings::insert(const TString& string)
{
std::pair<base::iterator,bool> result = base::insert( TSharedStringObject( string ) );
base::iterator it = result.first;
if ( result.second )
    {
    ((ITSharedStringObjectFromTSharedStrings&)*it).SetId( distance( base::begin(), it ) );
    }
return TSharedString( *this, it );
}

void CSharedStrings::erase(base::iterator& it)
{
base::iterator pos = it;
base::iterator end = base::end();
while ( ++pos != end )
    {
    --((ITSharedStringObjectFromTSharedStrings&)*pos);
    }
base::erase( it );
}

const TString CSharedStrings::filename() const
{
return m_dir + "/sharedStrings.xml";
}

ECONTENTTYPE CSharedStrings::type() const
{
return ECT_SHARED_STRING_TABLE;
}

