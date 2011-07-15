#include <zip.h>
#include "cdocxlsx.h"
#include "ccontent.h"
#include "crelationships.h"

CDocXLSX::CDocXLSX():
    m_workbook( "xl", base::m_relationships )
{
}

int CDocXLSX::save(const TString& filename) const
{
TZip archive;
int ret = archive.create( filename );
//TODO: ret
TContent content;
ret = m_workbook.save( archive, content );
//TODO: ret
ret = content.save( archive );
//TODO: ret
ret = archive.add_dir( "_rels" );
//TODO: ret
ret = m_relationships.save( archive, "_rels/.rels" );
return ret;
}

