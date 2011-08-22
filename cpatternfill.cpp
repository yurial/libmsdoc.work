#include <sstream>
#include <map>
#include "cpatternfill.h"

std::map<EPATTERN,TString>  g_patterntypes;

CPatternFill::CPatternFill(const TColor& fg, const TColor& bg, EPATTERN pattern):
    m_fg( fg ), m_bg( bg ), m_pattern( pattern )
{
}

bool CPatternFill::operator <  (const CPatternFill& rvalue) const
{
return false; //TODO:
}

TString CPatternFill::save() const
{
std::stringstream fill;
fill << "<patternFill>\n";

fill << "<fgColor>\n";
fill << m_fg.save();
fill << "<fgColor>\n";

fill << "<bgColor>\n";
fill << m_bg.save();
fill << "<bgColor>\n";

fill << "<patternType>\n";
fill << g_patterntypes[ m_pattern ];
fill << "</patternType>\n";

fill << "<patternFill/>\n";
return fill.str();
}

