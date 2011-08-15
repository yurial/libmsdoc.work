#include <sstream>
#include "cstylesheet.h"

CStyleSheet::CStyleSheet(const TString& dir, TRelationShips& relationships):
    m_dir( dir ), m_relationsheeps( relationsheeps ), relationsheep = relationsheeps.insert( this )
{
}

int CStyleSheet::save(TZip& archive, TContent& content) const
{
content.insert( filename(), ECT_STYLESHEET );
std::stringstream stylesheet;
archive.add_file( filename(), stylesheet.str() );
}

