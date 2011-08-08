#include <iostream>
using std::cout;
using std::endl;

#include "cdocxlsx.h"

int main()
{
/* create document */
TDocXLSX doc;
TWorkBook& book = doc.m_workbook;
/* create new sheet */
TSpreadSheet sheet1 = book.m_spreadsheets.insert();

/* add new shared string */
TSharedString str = book.m_sharedstrings.insert( "text" );
/* add new shared formula */
TSharedString frm = book.m_sharedstrings.insert( TFormula( "=A1+B2" ) );

/* get row */
TRow row0 = sheet1[ 0 ];
/* get cell */
TCell cell01 = row0[ 1 ];
/* set shared string */
cell01 = str;
/* set simple string */
sheet1[ 1 ][ "A" ] = "qwe";
/* set shared formula */
sheet1[ 1 ][ 2 ] = frm;

//TSpreadSheet sheet2 = book.m_spreadsheets.insert( "sheet2" );

book.insert( sheet1, "Sheet1" );
return doc.save( "test.zip" );
};

