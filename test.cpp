#include <iostream>
using std::cout;
using std::endl;

#include "cdocxlsx.h"

int main()
{
/* create document */
TDocXLSX doc;
TWorkBook& book = doc.m_workbook;
/* font */
TFont font = book.m_stylesheet.m_fonts.insert( "Tahoma", 10, EFF_BOLD | EFF_ITALIC );
/* fill */
TFill fill = book.m_stylesheet.m_fills.insert( TPatternFill( TColor(), TColor(), EPATTERN_SOLID ) );
/* cellxf */
TCellXF cellfmt0 = book.m_stylesheet.m_cellxfs.insert( font, fill );
/* create new sheet */
TSpreadSheet sheet1 = book.m_spreadsheets.insert();

/* add new shared string */
TSharedString str1 = book.m_sharedstrings.insert( "text1" );
book.m_sharedstrings.insert( "text3" );
TSharedString str2 = book.m_sharedstrings.insert( "text2" );
/* add new shared formula */
TFormula frm( "=A1+B1" );

/* get row */
TRow row0 = sheet1[ 0 ];
/* get cell */
TCell cell01 = row0[ 3 ];
/* apply format */
cell01 = cellfmt0;
/* set shared string */
cell01 = str1;
row0[ "E" ] = str2;
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

