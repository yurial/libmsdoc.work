#include <sstream>
#include "ccellxfs.h"

CCellXFs::CCellXFs()
{
base::insert( TCellXFObject() );
}

TCellXF TCellXFs::insert(const TFont& font, const TAlignment& align, const TBorder& border, const TFill& fill, const TNumFmt& numfmt/*, const TCellStyle& cellstyle*/)
{
std::pair<base::iterator,bool> result = base::insert( TCellXFObject( font, align, border, fill, numfmt ) );
base::iterator it = result.first;
if ( result.second )
    {
    ((ITCellXFObjectFromTCellXFs&)*it).SetId( distance( base::begin(), it ) );
    base::iterator pos = it;
    base::iterator end = base::end();
    while( ++pos != end )
        {
        ++((ITCellXFObjectFromTCellXFs&)*pos);
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

