#include "cdocxlsx.h"

int main()
{
TDocXLSX doc;
TSpreadSheet sheet = doc.m_spreadsheets.add( "Shit1" );
sheet.name() = "Sheet1";

TSharedString str = doc.m_sharedstrings.add( "text" );
return 0;
};

