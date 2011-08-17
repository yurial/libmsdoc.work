#include <sstream>
#include "cfontflags.h"

CFontFlags::CFontFlags():
    m_flags( 0 )
{
}

CFontFlags::CFontFlags(int flags):
    m_flags( flags )
{
}

CFontFlags::CFontFlags(EFONTFLAG flag):
    m_flags( flag )
{
}

bool CFontFlags::operator <  (const CFontFlags& rvalue) const
{
return m_flags < rvalue.m_flags;
}

CFontFlags& CFontFlags::operator =  (const CFontFlags& rvalue)
{
m_flags = rvalue.m_flags;
return *this;
}

CFontFlags& CFontFlags::operator =  (int flags)
{
m_flags = flags;
return *this;
}

CFontFlags& CFontFlags::operator =  (EFONTFLAG flag)
{
m_flags = flag;
return *this;
}

CFontFlags& CFontFlags::operator |= (const CFontFlags& rvalue)
{
m_flags |= rvalue.m_flags;
return *this;
}

CFontFlags& CFontFlags::operator |= (int flags)
{
m_flags |= flags;
return *this;
}

CFontFlags& CFontFlags::operator |= (EFONTFLAG flag)
{
m_flags |= flag;
return *this;
}

TString CFontFlags::save() const
{
std::stringstream flags;
if ( EFF_BOLD & m_flags )
    {
    flags << "<b/>\n";
    }
if ( EFF_CODENSE & m_flags )
    {
    flags << "<condense/>\n";
    }
if ( EFF_EXTEND & m_flags )
    {
    flags << "<extend/>\n";
    }
if ( EFF_ITALIC & m_flags )
    {
    flags << "<i/>\n";
    }
if ( EFF_OUTLINE & m_flags )
    {
    flags << "<outline/>\n";
    }
if ( EFF_SHADOW & m_flags )
    {
    flags << "<shadow/>\n";
    }
if ( EFF_STRIKE & m_flags )
    {
    flags << "<strinke/>\n";
    }
if ( EFF_UNDERLINE & m_flags )
    {
    flags << "<u/>\n";
    }
return flags.str();
}

