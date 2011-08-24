#include <sstream>
#include "cborderobject.h"

ITBorderObjectFromTBorders::ITBorderObjectFromTBorders():
    m_id( 0 )
{
}

void ITBorderObjectFromTBorders::SetId(int id)
{
m_id = id;
}

int ITBorderObjectFromTBorders::GetId() const
{
return m_id;
}

void ITBorderObjectFromTBorders::operator ++ ()
{
++m_id;
}

void ITBorderObjectFromTBorders::operator -- ()
{
--m_id;
}

ITBorderObjectFromTBorder::ITBorderObjectFromTBorder():
    m_links( NULL )
{
}

void ITBorderObjectFromTBorder::Link() const
{
++m_links;
}

int ITBorderObjectFromTBorder::UnLink() const
{
return --m_links;
}

CBorderObject::CBorderObject():
    m_down( false ), m_up( false ), m_outline( false )
{
}

CBorderObject::CBorderObject(const TBorderLine& left,
                             const TBorderLine& right,
                             const TBorderLine& top, 
                             const TBorderLine& bottom, 
                             const TBorderLine& diagonal, 
                             bool down,
                             bool up,
                             bool outline):
                             m_left( left ),
                             m_right( right ),
                             m_top( top ),
                             m_bottom( bottom ),
                             m_diagonal( diagonal ),
                             m_down( down ),
                             m_up( up ),
                             m_outline( outline )
{
}

bool CBorderObject::operator < (const CBorderObject& rvalue) const
{
if ( m_left < rvalue.m_left )
    {
    return true;
    }
else if ( rvalue.m_left < m_left )
    {
    return false;
    }
else if ( m_right < rvalue.m_right )
    {
    return true;
    }
else if ( rvalue.m_right < m_right )
    {
    return false;
    }
else if ( m_top < rvalue.m_top )
    {
    return true;
    }
else if ( rvalue.m_top < m_top )
    {
    return false;
    }
else if ( m_bottom < rvalue.m_bottom )
    {
    return true;
    }
else if ( rvalue.m_bottom < m_bottom )
    {
    return false;
    }
else if ( m_diagonal < rvalue.m_diagonal )
    {
    return true;
    }
else if ( rvalue.m_diagonal < m_diagonal )
    {
    return false;
    }
else if ( m_down < rvalue.m_down )
    {
    return true;
    }
else if ( rvalue.m_down < m_down )
    {
    return false;
    }
else if ( m_up < rvalue.m_up )
    {
    return true;
    }
else if ( rvalue.m_up < m_up )
    {
    return false;
    }
else if ( m_outline < rvalue.m_outline )
    {
    return true;
    }
else if ( rvalue.m_outline < m_outline )
    {
    return false;
    }
return false;
}

TString CBorderObject::save() const
{
if ( !IsSet() )
    {
    return "<border/>\n";
    }

std::stringstream border;
border << "<border";
if ( m_down )
    {
    border << " diagonalDown=\"1\"";
    }
if ( m_up )
    {
    border << " diagonalUp=\"1\"";
    }
if ( m_outline )
    {
    border << " outline=\"1\"";
    }
border << '>' << '\n';

border << m_left.save( "left" );
border << m_right.save( "right" );
border << m_top.save( "top" );
border << m_bottom.save( "bottom" );
border << m_diagonal.save( "diagonal" );

border << "</border>\n";

return border.str();
}

int CBorderObject::id() const
{
return GetId();
}

bool CBorderObject::IsSet() const
{
return m_down || m_up || m_outline || m_right.IsSet() || m_left.IsSet() || m_top.IsSet() || m_bottom.IsSet() || m_diagonal.IsSet();
}

