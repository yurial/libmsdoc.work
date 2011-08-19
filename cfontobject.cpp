#include <sstream>
#include "cfontobject.h"

ITFontObjectFromTFonts::ITFontObjectFromTFonts():
    m_id( 0 )
{
}

ITFontObjectFromTFonts::ITFontObjectFromTFonts(const ITFontObjectFromTFonts& origin):
    m_id( origin.m_id )
{
}

void ITFontObjectFromTFonts::SetId(int id)
{
m_id = id;
}

int ITFontObjectFromTFonts::GetId() const
{
return m_id;
}

void ITFontObjectFromTFonts::operator ++ ()
{
++m_id;
}

void ITFontObjectFromTFonts::operator -- ()
{
--m_id;
}

ITFontObjectFromTFont::ITFontObjectFromTFont():
    m_links( 0 )
{
}

ITFontObjectFromTFont::ITFontObjectFromTFont(const ITFontObjectFromTFont& origin):
    m_links( origin.m_links )
{
}

void ITFontObjectFromTFont::Link() const
{
++m_links;
}

int ITFontObjectFromTFont::UnLink() const
{
return --m_links;
}

CFontObject::CFontObject():
    m_size( 0 )
{
}

CFontObject::CFontObject(TString name, int size, TFontFlags flags):
    m_name( name ), m_size( size ), m_flags( flags )
{
}

CFontObject::CFontObject(const CFontObject& origin):
    ITFontObjectFromTFonts( origin ),
    ITFontObjectFromTFont( origin ),
    m_name( origin.m_name ), m_size( origin.m_size ), m_flags( origin.m_flags )
{
}

bool CFontObject::operator <  (const CFontObject& rvalue) const
{
if ( m_size < rvalue.m_size )
    {
    return true;
    }
else if ( rvalue.m_size < m_size )
    {
    return false;
    }
else if ( m_flags < rvalue.m_flags )
    {
    return true;
    }
else if ( rvalue.m_flags < m_flags )
    {
    return false;
    }
else if( m_name < rvalue.m_name )
    {
    return true;
    }
else if ( rvalue.m_name < m_name )
    {
    return false;
    }
return false;
}

int CFontObject::id() const
{
return ITFontObjectFromTFonts::GetId();
}

TString CFontObject::save() const
{
std::stringstream font;
font << "<font>\n";
if ( 0 != m_size )
    {
    font << "<sz val=\"" << m_size << "\"/>\n";
    }
if ( 0 != m_name.size() )
    {
    font << "<name val=\"" << m_name << "\"/>\n";
    }
font << ((const ITFontFlagsFromTFontObject&)m_flags).save();
font << "</font>\n";
return font.str();
}

