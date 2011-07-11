#include "ccellobject.h"

CCellObject::CCellObject()
{
m_shastr = NULL;
m_str = NULL;
}

CCellObject::~CCellObject()
{
if ( NULL != m_str )
    {
    delete m_str;
    #ifdef DEBUG
    m_str = NULL;
    #endif
    }
if ( NULL != m_shastr )
    {
    delete m_shastr;
    #ifdef DEBUG
    m_shastr = NULL;
    #endif
    }
}

CCellObject& CCellObject::operator = (const TString& str)
{

if ( NULL != m_str )
    {
    delete m_str;
    }
if ( NULL != m_shastr )
    {
    delete m_shastr;
    m_shastr = NULL;
    }
m_str = new TString( str );
return *this;
}

CCellObject& CCellObject::operator = (const TSharedString& str)
{
if ( NULL != m_str )
    {
    delete m_str;
    m_str = NULL;
    }
if ( NULL != m_shastr )
    {
    delete m_shastr;
    }
m_shastr = new TSharedString( str );
return *this;
}

