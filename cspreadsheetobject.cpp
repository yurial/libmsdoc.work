#include <sstream>
#include "cspreadsheetobject.h"

CSpreadSheetObject::CSpreadSheetObject(const TString& dir, TRelationShips& relationships):
    m_relationships( relationships ), m_relationship( relationships.insert( this ) ), m_dir( dir )
{
}

CSpreadSheetObject::CSpreadSheetObject(const CSpreadSheetObject& origin):
    m_relationships( origin.m_relationships ), m_relationship( m_relationships.insert( this ) ), m_dir( origin.m_dir )   
{
}

CSpreadSheetObject::~CSpreadSheetObject()
{
m_relationships.erase( m_relationship );
}

TRow CSpreadSheetObject::operator [] (int index)
{
std::pair<TRows::iterator,bool> row = m_rows.insert( std::make_pair( index, TRowObject( index ) ) );
return row.first;
}

int CSpreadSheetObject::save(TZip& archive, TContent& content) const
{
content.insert( filename(), ECT_WORKSHEET );
std::stringstream sheet;
sheet << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
sheet << "<worksheet ";
sheet << "xmlns=\"http://schemas.openxmlformats.org/spreadsheetml/2006/main\">";
//sheet << "xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\">\n";
//TODO default settings
sheet << "<sheetData>\n";
//rows
TRows::const_iterator it = m_rows.begin();
TRows::const_iterator end = m_rows.end();
for (; it != end; ++it)
    {
    it->second.save( sheet );
    }

sheet << "</sheetData>\n";
sheet << "</worksheet>\n";
archive.add_file( filename(), sheet.str() );
return 0;
}

const TString CSpreadSheetObject::filename() const
{
std::stringstream filename;
filename << m_dir << "/sheet" << m_relationship.rid() << ".xml";
return filename.str();
}

ERELTYPE CSpreadSheetObject::type() const
{
return ERT_WORKSHEET;
}

int CSpreadSheetObject::rid() const
{
return m_relationship.rid();
}

