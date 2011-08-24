#include <sstream>
#include "cfillobject.h"

ITFillObjectFromTFills::ITFillObjectFromTFills():
    m_id( 0 )
{
}

ITFillObjectFromTFills::ITFillObjectFromTFills(const ITFillObjectFromTFills& origin):
    m_id( origin.m_id )
{
}

void ITFillObjectFromTFills::SetId(int id)
{
m_id = id;
}

int ITFillObjectFromTFills::GetId() const
{
return m_id;
}

void ITFillObjectFromTFills::operator ++ ()
{
++m_id;
}

void ITFillObjectFromTFills::operator -- ()
{
--m_id;
}

ITFillObjectFromTFill::ITFillObjectFromTFill():
    m_links( 0 )
{
}

ITFillObjectFromTFill::ITFillObjectFromTFill(const ITFillObjectFromTFill& origin):
    m_links( origin.m_links )
{
}

void ITFillObjectFromTFill::Link() const
{
++m_links;
}

int ITFillObjectFromTFill::UnLink() const
{
return --m_links;
}

CFillObject::CFillObject():
    m_type( EFILL_NONE ), m_object( NULL )
{
}

CFillObject::CFillObject(const CFillObject& origin):
    m_type( origin.m_type )
{
switch( m_type )
    {
    case EFILL_GRADIENT:
        {
        m_object = new TGradientFill( *(TGradientFill*)origin.m_object );
        }
        break;
    case EFILL_PATTERN:
        {
        m_object = new TPatternFill( *(TPatternFill*)origin.m_object );
        }
        break;
    case EFILL_NONE:
        {
        m_object = NULL;
        }
    }
}

CFillObject::CFillObject(const TGradientFill& fill):
    m_type( EFILL_GRADIENT ), m_object( new TGradientFill( fill ) )
{
}

CFillObject::CFillObject(const TPatternFill& fill):
    m_type( EFILL_PATTERN ), m_object( new TPatternFill( fill ) )
{
}

CFillObject::~CFillObject()
{
clear();
}

void CFillObject::clear()
{
switch( m_type )
    {
    case EFILL_GRADIENT:
        {
        delete (TGradientFill*)m_object;
        }
        break;
    case EFILL_PATTERN:
        {
        delete (TPatternFill*)m_object;
        }
        break;
    case EFILL_NONE:
        {
        }
    }
m_type = EFILL_NONE;
m_object = NULL;
}

bool CFillObject::operator < (const CFillObject& rvalue) const
{
if ( m_type < rvalue.m_type )
    {
    return true;
    }
else if ( rvalue.m_type < m_type )
    {
    return false;
    }
switch( m_type )
    {
    case EFILL_NONE:
        return false;
    case EFILL_GRADIENT:
        {
        if ( ((ITGradientFillFromTFillObject*)m_object)->operator < ( *((TGradientFill*)rvalue.m_object) ) )
            {
            return true;
            }
        else if ( ((ITGradientFillFromTFillObject*)rvalue.m_object)->operator < ( *((TGradientFill*)m_object) ) )
            {
            return false;
            }
        }
        break;
    case EFILL_PATTERN:
        {
        if ( ((ITPatternFillFromTFillObject*)m_object)->operator < ( *((TPatternFill*)rvalue.m_object) ) )
            {
            return true;
            }
        else if ( ((ITPatternFillFromTFillObject*)rvalue.m_object)->operator < ( *((TPatternFill*)m_object) ) )
            {
            return false;
            }
        }
        break;
    }
return false;
}

TString CFillObject::save() const
{
std::stringstream fill;

switch( m_type )
    {
    case EFILL_GRADIENT:
        {
        fill << "<fill>\n";
        fill << ((ITGradientFillFromTFillObject*)m_object)->save();
        fill << "</fill\n>";
        }
        break;
    case EFILL_PATTERN:
        {
        if ( ((TPatternFill*)m_object)->IsSet() )
            {
            fill << "<fill>\n";
            fill << ((ITPatternFillFromTFillObject*)m_object)->save();
            fill << "</fill>\n";
            }
        else
            {
            fill << "<fill/>\n";
            }
        }
        break;
    case EFILL_NONE:
        {
        fill << "<fill/>\n";
        }
    }
return fill.str();
}

int CFillObject::id() const
{
return GetId();
}

