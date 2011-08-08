#include "csharedstrings.h"

CSharedStrings::CSharedStrings()
{
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

