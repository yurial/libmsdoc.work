#include <iostream>
using std::cout;
using std::endl;

#include "cdocxlsx.h"

int main()
{
/* create document */
TDocXLSX doc;
TWorkBook& book = doc.m_workbook;
TFont font = book.m_stylesheet.m_fonts.insert( "Times New Roman", 10, EFF_BOLD | EFF_ITALIC );
/* create new sheet */
TSpreadSheet sheet1 = book.m_spreadsheets.insert();

/* add new shared string */
TSharedString str = book.m_sharedstrings.insert( "text" );
/* add new shared formula */
TFormula frm( "=A1+B1" );

/* get row */
TRow row0 = sheet1[ 0 ];
/* get cell */
TCell cell01 = row0[ 3 ];
/* set shared string */
cell01 = str;
row0[ "E" ] = str;
/* set int */
sheet1[ 0 ][ "A" ] = 1;
/* set double */
sheet1[ 0 ][ "B" ] = 1.5;
/* set simple string */
sheet1[ 1 ][ "A" ] = "qwe";
/* set formula */
sheet1[ 0 ][ "C" ] = frm;
/* set date */
//sheet1[ 1 ][ "B" ] = TDate( time(NULL) );

//TSpreadSheet sheet2 = book.m_spreadsheets.insert( "sheet2" );

book.insert( sheet1, "Sheet1" );
return doc.save( "test.zip" );
};

