#ifndef CZIPH
#define CZIPH

#include <zip.h>

class CZip;
typedef CZip TZip;

#include "cstring.h"

class CZip
{
protected:
zip*    m_archive;

public:
    CZip();
    ~CZip();
int create(const TString& filename);
int open(const TString& filename);
int close();

int add_dir(const TString& dirname);
int add_file(const TString& filename, const TString& buff);
};

#endif

