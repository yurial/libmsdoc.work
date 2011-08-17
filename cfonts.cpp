#include <sstream>
#include "cfonts.h"

TFont CFonts::insert(TString name, int size, TFontFlags flags)
{
std::pair<base::iterator,bool> result = base::insert( TFontObject( name, size, flags ) );
base::iterator it = result.first;
if ( result.second ) //new element
    {
    ((ITFontObjectFromTFonts&)*it).SetId( distance( base::begin(), it ) );
    }
return TFont( *this, it );
}

TString CFonts::save() const
{
std::stringstream fonts;
if ( 0 < base::size() )
    {
    fonts << "<fonts>\n";
    base::const_iterator it = base::begin();
    base::const_iterator end = base::end();
    for (; it != end; ++it)
        {
        fonts << ((ITFontObjectFromTFonts&)*it).save();
        }
    fonts << "</fonts>\n";
    }
return fonts.str();
}

void CFonts::erase(base::iterator it)
{
base::iterator pos = it;
base::iterator end = base::end();
while ( ++pos != end )
    {
    --((ITFontObjectFromTFonts&)*pos);
    }
base::erase( it );
}

