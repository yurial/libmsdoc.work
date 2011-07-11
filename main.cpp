#include <iostream>
using std::cout;
using std::endl;

#include "cdocxlsx.h"

int main()
{
TDocXLSX doc;
TSpreadSheet sheet = doc.m_spreadsheets.add( "Shit1" );
sheet.name() = "Sheet1";
cout << sheet.name() << endl;

TSharedString str = doc.m_sharedstrings.add( "text" );
cout << str.id() << endl;
TSharedString frm = doc.m_sharedstrings.add( TFormula( "=A1+B2" ) );
cout << frm.id() << endl;
doc.m_sharedstrings.erase( str );
cout << frm.id() << endl;
return 0;
};

