#include <string.h>

#include "czip.h"

CZip::CZip()
{
m_archive = NULL;
}

CZip::~CZip()
{
if ( NULL != m_archive )
    {
    zip_close( m_archive );
    }
}

int CZip::create(const TString& filename)
{
int ret;
m_archive = zip_open( filename.c_str(), ZIP_CREATE, &ret );
return -(NULL == m_archive);
}

int CZip::add_dir(const TString& dir)
{
int ret = zip_add_dir( m_archive, dir.c_str() );
return ret;
}

int CZip::add_file(const TString& filename, const TString& buff)
{
char* dynamic_buff = new char [ buff.size() ];
memcpy( dynamic_buff, buff.c_str(), buff.size() );
zip_source* source = zip_source_buffer( m_archive, dynamic_buff, buff.size(), 1 );
if ( NULL == source )
    {
    delete []dynamic_buff;
    return -1;
    }
int ret = zip_add( m_archive, filename.c_str(), source );
if ( -1 == ret )
    {
    zip_source_free( source );
    return -1;
    }
return 0;
}

