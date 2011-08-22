#include <sstream>
#include "ccellxfs.h"

CCellXFs::CCellXFs()
{
base::insert( TCellXFObject() );
}

TCellXF TCellXFs::insert(const TFont& font, const TFill& fill/*, const TBorder& border*//*, const TNumFmt& numfmt*//*, const TCellStyle& cellstyle*/)
{
std::pair<base::iterator,bool> result = base::insert( TCellXFObject( font, fill ) );
base::iterator it = result.first;
if ( result.second )
    {
    ((ITCellXFObjectFromTCellXFs&)*it).SetId( distance( base::begin(), it ) );
    base::iterator pos = it;
    base::iterator end = base::end();
    while( ++pos != end )
        {
        ++((ITCellXFObjectFromTCellXFs&)*it);
        }
    }
return TCellXF( *this, it );
}

TString TCellXFs::save() const
{
std::stringstream cellxfs;
cellxfs << "<cellXfs count=\"" << base ::size() << "\">\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it )
    {
    cellxfs << ((ITCellXFObjectFromTCellXFs&)*it).save();
    }
cellxfs << "</cellXfs>\n";
return cellxfs.str();
}

void TCellXFs::erase(base::iterator& cellfx)
{
if ( base::begin() == cellfx )
    {
    return;
    }
base::iterator it = cellfx;
base::iterator end = base::end();
while ( ++it != end )
    {
    --((ITCellXFObjectFromTCellXFs&)*it);
    }
base::erase( cellfx );
}

