#ifndef CDOCXLSX
#define CDOCXLSX

class CDocXLSX;
typedef CDocXLSX TDocXLSX;

#include "cspreadsheets.h"
#include "csharedstrings.h"

class CDocXLSX
{
public:
TSpreadSheets   m_spreadsheets;
TSharedStrings  m_sharedstrings;
};

#endif

