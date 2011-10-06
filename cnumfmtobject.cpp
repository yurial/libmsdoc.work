#include <sstream>
#include "cnumfmtobject.h"

ITNumFmtObjectFromTNumFmts::ITNumFmtObjectFromTNumFmts():
    m_id( 0 )
{
}

ITNumFmtObjectFromTNumFmts::ITNumFmtObjectFromTNumFmts(const ITNumFmtObjectFromTNumFmts& origin):
    m_id( origin.m_id )
{
}

void ITNumFmtObjectFromTNumFmts::SetId(int id)
{
m_id = id;
}

int ITNumFmtObjectFromTNumFmts::GetId() const
{
return m_id;
}

void ITNumFmtObjectFromTNumFmts::operator ++ ()
{
++m_id;
}

void ITNumFmtObjectFromTNumFmts::operator -- ()
{
--m_id;
}

ITNumFmtObjectFromTNumFmt::ITNumFmtObjectFromTNumFmt():
    m_links( 0 )
{
}

ITNumFmtObjectFromTNumFmt::ITNumFmtObjectFromTNumFmt(const ITNumFmtObjectFromTNumFmt& origin):
    m_links( origin.m_links )
{
}

void ITNumFmtObjectFromTNumFmt::Link() const
{
++m_links;
}

int ITNumFmtObjectFromTNumFmt::UnLink() const
{
return --m_links;
}

CNumFmtObject::CNumFmtObject(ENUMFMT fmt)
{
SetId( fmt );
}

CNumFmtObject::CNumFmtObject(TString fmt):
    m_fmt( fmt )
{
}

CNumFmtObject::CNumFmtObject(const CNumFmtObject& origin):
    ITNumFmtObjectFromTNumFmts( origin ),
    ITNumFmtObjectFromTNumFmt( origin ),
    m_fmt( origin.m_fmt )
{
}

bool CNumFmtObject::operator < (const CNumFmtObject& rvalue) const
{
if ( m_fmt.empty() && rvalue.m_fmt.empty() )
    {
    if ( m_id < rvalue.m_id )
        {
        return true;
        }
    }
if ( m_fmt < rvalue.m_fmt )
    {
    return true;
    }
else if ( rvalue.m_fmt < m_fmt )
    {
    return false;
    }
return false;
}

int CNumFmtObject::id() const
{
return ITNumFmtObjectFromTNumFmts::GetId();
}

TString CNumFmtObject::save() const
{
std::stringstream numfmt;
numfmt << "<numFmt";
numfmt << " numFmtId=\"" << id() <<'"';
if ( m_fmt.size() )
    {
    numfmt << " formatCode=\"" << m_fmt << '"';
    }
numfmt << "/>\n";
return numfmt.str();
}

