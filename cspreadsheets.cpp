#include <sstream>

#include "cspreadsheets.h"

CSpreadSheets::CSpreadSheets(const TString& dir, TRelationShips& relationships):
    m_dir( dir ), m_relationships( relationships )
{
}

CSpreadSheets::~CSpreadSheets()
{
}

int CSpreadSheets::save(TZip& archive, TContent& content) const
{
archive.add_dir( m_dir );
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (; it != end; ++it)
    {
    it->save( archive, content );
    //TODO: ret
    }
return 0;
}

TSpreadSheet CSpreadSheets::insert()
{
return base::insert( end(), TSpreadSheetObject( m_dir, m_relationships ) );
}

