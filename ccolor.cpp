#include <sstream>
#include "ccolor.h"

CColor::CColor():
    m_rgb( 0 )
{
}

CColor::CColor(int rgb):
    m_rgb( rgb )
{
}

bool CColor::operator <  (const CColor& rvalue) const
{
return m_rgb < rvalue.m_rgb;
}

TString CColor::save() const
{
std::stringstream color;
color << " rgb=\"" << std::hex << m_rgb << "\"";
return color.str();
}

