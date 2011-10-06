#include <sstream>
#include "cnumfmts.h"

CNumFmts::CNumFmts()
{
}

TNumFmtsContainer::const_iterator CNumFmts::begin() const
{
return base::begin();
}

TNumFmt CNumFmts::insert(ENUMFMT fmt)
{
std::pair<base::iterator,bool> result = base::insert( TNumFmtObject( fmt ) );
return TNumFmt( *this, result.first );
}

TNumFmt CNumFmts::insert(const TString& fmt)
{
std::pair<base::iterator,bool> result = base::insert( TNumFmtObject( fmt ) );
base::iterator it = result.first;
if ( result.second )
    {
    base::iterator::difference_type dist = base::rbegin()->GetId() + 1;
    if (dist < 128)
        {
        dist = 128;
        }
    ((ITNumFmtObjectFromTNumFmts&)*it).SetId( dist );

    base::iterator pos = it;
    base::iterator end = base::end();
    while ( ++pos != end )
        {
        ++((ITNumFmtObjectFromTNumFmts&)*pos);
        }
    }
return TNumFmt( *this, it );
}

TString CNumFmts::save() const
{
std::stringstream numfmts;
numfmts << "<numFmts>\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    numfmts << ((ITNumFmtObjectFromTNumFmts&)*it).save();
    }
numfmts << "</numFmts>\n";
return numfmts.str();
}

void CNumFmts::erase(const base::iterator& numfmt)
{
base::iterator pos = numfmt;
base::iterator end = base::end();
while ( ++pos != end )
    {
    --((ITNumFmtObjectFromTNumFmts&)*pos);
    }
base::erase( numfmt );
}

