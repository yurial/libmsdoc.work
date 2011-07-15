#ifndef CDOCXLSX
#define CDOCXLSX

class CDocXLSX;
typedef CDocXLSX TDocXLSX;

#include "cdoc.h"
#include "cworkbook.h"

class CDocXLSX:
    public TDoc
{
public:
TWorkBook   m_workbook;

protected:
typedef TDoc base;

public:
        CDocXLSX();
int     save(const TString& filename) const;
};

#endif

