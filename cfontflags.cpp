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

