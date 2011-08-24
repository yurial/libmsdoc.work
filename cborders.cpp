#include <sstream>
#include "cborders.h"

CBorders::CBorders():
    m_default( *this, base::insert( TBorderObject() ).first )
{
}

TBordersContainer::const_iterator CBorders::begin() const
{
return base::begin();
}

TBorder CBorders::insert()
{
return TBorder( *this, base::begin() );
}

TBorder CBorders::insert(
    const TBorderLine& left,
    const TBorderLine& right,
    const TBorderLine& top,
    const TBorderLine& bottom,
    const TBorderLine& diagonal,
    bool down,
    bool up,
    bool outline )
{
std::pair<base::iterator,bool> result = base::insert( TBorderObject( left, right, top, bottom, diagonal, down, up, outline ) );

base::iterator it = result.first;
if ( result.second )
    {
    ((ITBorderObjectFromTBorders&)*it).SetId( distance( base::begin(), it ) );
    base::iterator pos = it;
    base::iterator end = base::end();
    while ( ++pos != end )
        {
        ++((ITBorderObjectFromTBorders&)*pos);
        }
    }
return TBorder( *this, it );
}

void CBorders::erase(TBordersContainer::iterator& border)
{
base::iterator it = border;
base::iterator end = base::end();
while ( ++it != end )
    {
    --((ITBorderObjectFromTBorders&)*it);
    }
base::erase( border );
}

TString CBorders::save() const
{
std::stringstream borders;
borders << "<borders>\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    borders << ((ITBorderObjectFromTBorders&)*it).save();
    }
borders << "</borders>\n";
return borders.str();
}

