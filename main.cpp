#include <iostream>
using std::cout;
using std::endl;

#include "cdocxlsx.h"

int main()
{
/* create document */
TDocXLSX doc;
/* create new sheet */
TSpreadSheet sheet = doc.m_spreadsheets.add( "Shit1" );
/*  */
sheet.name() = "Sheet1";

/* add new shared string */
TSharedString str = doc.m_sharedstrings.add( "text" );
/* add new shared formula */
TSharedString frm = doc.m_sharedstrings.add( TFormula( "=A1+B2" ) );

/* get row */
TRow row0 = sheet[ 0 ];
/* get cell */
TCell cell01 = row0[ 1 ];
/* set shared string */
cell01 = str;
/* set simple string */
sheet[ 1 ][ "A" ] = "qwe";
/* set shared formula */
sheet[ 1 ][ 2 ] = frm;

return 0;
};

