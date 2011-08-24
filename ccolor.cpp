#include <sstream>
#include <iomanip>
#include "ccolor.h"

CColor::CColor():
   m_set( false ), m_rgb( 0 )
{
}

CColor::CColor(int rgb):
    m_set( true ), m_rgb( rgb )
{
}

bool CColor::operator <  (const CColor& rvalue) const
{
return m_rgb < rvalue.m_rgb;
}

TString CColor::save() const
{
std::stringstream color;
color << " rgb=\"" << std::hex << std::setw(8) <<std::setfill( '0' ) << m_rgb << "\"";
return color.str();
}

bool CColor::IsSet() const
{
return m_set;
}

