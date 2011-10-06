#include <sstream>
#include "ccellxfobject.h"

ITCellXFObjectFromTCellXFs::ITCellXFObjectFromTCellXFs():
    m_id( 0 )
{
}

ITCellXFObjectFromTCellXFs::ITCellXFObjectFromTCellXFs(const ITCellXFObjectFromTCellXFs& origin):
    m_id( origin.m_id )
{
}

void ITCellXFObjectFromTCellXFs::SetId(int id)
{
m_id = id;
}

int ITCellXFObjectFromTCellXFs::GetId() const
{
return m_id;
}

void ITCellXFObjectFromTCellXFs::operator ++ ()
{
++m_id;
}

void ITCellXFObjectFromTCellXFs::operator -- ()
{
--m_id;
}

ITCellXFObjectFromTCellXF::ITCellXFObjectFromTCellXF():
    m_links( 0 )
{
}

ITCellXFObjectFromTCellXF::ITCellXFObjectFromTCellXF(const ITCellXFObjectFromTCellXF& origin):
    m_links( origin.m_links )
{
}

void ITCellXFObjectFromTCellXF::Link() const
{
++m_links;
}

int ITCellXFObjectFromTCellXF::UnLink() const
{
return --m_links;
}

CCellXFObject::CCellXFObject(const TFont& font, const TAlignment& align, const TBorder& border, const TFill& fill, const TNumFmt& numfmt/*, const TCellStyleFX& cellstylexf*/):
    base( font, align, border, fill, numfmt )/*, m_cellstylexf*/
{
}

CCellXFObject::CCellXFObject(const CCellXFObject& origin):
    ITCellXFObjectFromTCellXF( origin ), base( origin )/*, m_cellstylexf( origin.m_cellstylexf )*/
{
}

bool CCellXFObject::operator <  (const CCellXFObject& rvalue) const
{
if ( base::operator < ( rvalue ) )
    {
    return true;
    }
else if ( rvalue.base::operator < ( *this ) )
    {
    return false;
    }
/*
else if ( m_cellstylexf < rvalue.m_cellstylexf )
    {
    return true;
    }
else if ( rvalues.m_cellstylexf < m_cellstylexf )
    {
    return false;
    }
return false;
*/
return false;
}

TString CCellXFObject::save() const
{
std::stringstream xf;
xf << "<xf";
ITNumFmtFromTCellXFObject& numfmt = (ITNumFmtFromTCellXFObject&)m_numfmt;
if ( numfmt.IsSet() )
    {
    xf << " numFmtId=\"" << numfmt.id() << '\"';
    }
else
    {
    xf << " numFmtId=\"0\"";
    }
ITFontFromTCellXFObject& ifont = (ITFontFromTCellXFObject&)m_font;
if ( ifont.IsSet() )
    {
    xf << " fontId=\"" << ifont.id() << '\"';
    }
else
    {
    xf << " fontId=\"0\"";
    }
ITFillFromTCellXFObject& ifill = (ITFillFromTCellXFObject&)m_fill;
if ( ifill.IsSet() )
    {
    xf << " fillId=\"" << ifill.id() << '\"';
    }
else
    {
    xf << " fillId=\"0\"";
    }
ITBorderFromTCellXFObject& iborder = (ITBorderFromTCellXFObject&)m_border;
if ( iborder.IsSet() )
    {
    xf << " borderId=\"" << iborder.id() << '\"';
    }
else
    {
    xf << " borderId=\"0\"";
    }
xf << ">\n";
xf << m_align.save();
xf << "</xf>\n";
return xf.str();
}

int CCellXFObject::id() const
{
return GetId();
}

