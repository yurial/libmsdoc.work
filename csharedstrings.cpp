#include "csharedstrings.h"

CSharedStrings::CSharedStrings()
{
}

TSharedString CSharedStrings::add(const TString& string)
{
std::pair<base::iterator,bool> result = insert( std::make_pair( TSharedStringObject( string ), size() ) );
return result.first;
}

TSharedString CSharedStrings::add(const TFormula& formula)
{
std::pair<base::iterator,bool> result = insert( std::make_pair( TSharedStringObject( formula ), size() ) );
return result.first;
}

void CSharedStrings::erase(TSharedString& sharedstring)
{
base::iterator pos = sharedstring;
while ( --pos != end() )
    {
    --pos->second;
    }
base::erase( sharedstring );
}

