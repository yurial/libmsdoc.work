#include <sstream>
#include "cfills.h"

CFills::CFills():
    m_default0( *this, base::insert( TFillObject( TPatternFill() ) ).first ),
    m_default1( *this, base::insert( TFillObject( TPatternFill( TColor(), TColor(), EPATTERN_GRAY125) ) ).first )
{
}

TFill CFills::insert()
{
return TFill( *this, base::begin() );
}

TFillsContainer::const_iterator CFills::begin() const
{
return base::begin();
}

template <class T>
TFill CFills::base_insert(const T& fill)
{
std::pair<base::iterator,bool> result = base::insert( TFillObject( fill ) );
base::iterator it = result.first;
if ( result.second )
    {
    ((ITFillObjectFromTFills&)*it).SetId( distance( base::begin(), it ) );
    base::iterator pos = it;
    base::iterator end = base::end();
    while ( ++pos != end )
        {
        ++((ITFillObjectFromTFills&)*pos);
        }
    }
return TFill( *this, it );
}

TFill CFills::insert(const TGradientFill& fill)
{
return base_insert( fill );
}

TFill CFills::insert(const TPatternFill& fill)
{
return base_insert( fill );
}

void CFills::erase(base::iterator& fill)
{
base::iterator it = fill;
base::iterator end = base::end();
while ( ++it != end )
    {
    --((ITFillObjectFromTFills&)*it);
    }
base::erase( fill );
}

TString CFills::save() const
{
std::stringstream fills;
fills << "<fills>\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    fills << ((ITFillObjectFromTFills&)*it).save();
    }
fills << "</fills>\n";
return fills.str();
}

