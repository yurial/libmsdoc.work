#include <sstream>
#include "cworkbook.h"

CWorkBook::CWorkBook(const TString& dir, TRelationShips& relationships):
    m_dir( dir ), m_relationship( relationships.insert( this ) ), m_spreadsheets( m_dir + "/worksheets", m_relationships )
{
}

TWorkBookList CWorkBook::insert(IWorkBookList& list, const TString& name)
{
return base::insert( base::end(), TWorkBookListObject( &list, name ) );
}

int CWorkBook::save(TZip& archive, TContent& content) const
{
content.insert( filename(), ECT_WORKBOOK );
TString reldir = m_dir + "/_rels";
TString relfile = reldir + "/workbook.xml.rels";
archive.add_dir( m_dir );
archive.add_dir( reldir );
int ret = m_spreadsheets.save( archive, content );
//TODO: ret
ret = m_relationships.save( archive, relfile );
//TODO ret

std::stringstream workbook;
workbook << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
workbook << "<workbook ";
workbook << "xmlns=\"http://schemas.openxmlformats.org/spreadsheetml/2006/main\" ";
workbook << "xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\">\n";

workbook << "<sheets>\n";
base::const_iterator it = base::begin();
base::const_iterator end = base::end();
for (int id = 1; it != end; ++it, ++id)
    {
    workbook << "<sheet name=\"" << it->name() << "\" sheetId=\"" << id << "\" r:id=\"rId" << it->rid() << "\"/>\n";
    }
workbook << "</sheets>\n";

workbook << "</workbook>\n";

ret = archive.add_file( m_dir + "/workbook.xml", workbook.str() );

return ret;
}

const TString CWorkBook::filename() const
{
return m_dir + "/workbook.xml";
}

ERELTYPE CWorkBook::type() const
{
return ERT_OFFICEDOCUMENT;
}

int CWorkBook::rid() const
{
return m_relationship.rid();
}

