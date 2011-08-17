#ifndef CSTYLESHEETH
#define CSTYLESHEETH

class CStyleSheet;
typedef CStyleSheet TStyleSheet;

#include "cbaserelationshipobject.h"
#include "cfontstyles.h"

class ITStyleSheetFromTWorkBook
{
public:
virtual int save(TZip& archive, TContent& content) const = 0;
};

class CStyleSheet:
    public ITStyleSheetFromTWorkBook,
    public TBaseRelationShipObject
{
protected:
TString             m_dir;

const TString       filename() const;
ECONTENTTYPE        type() const;

virtual int save(TZip& archive, TContent& content) const;

public:
                    CStyleSheet(const TString& dir, TRelationShips& relationships);

TFontStyles         m_fonts;
//TBorderStyles   //borders
//TFillStyles     //fills
//TNumFormat      //numFmts
//dxfs
//TCellStyle  //cellXfs
//cellStyles (Cell Styles)
//cellStyleXfs (Formatting Records)
//tableStyles (Table Styles)
//colors (Colors)
//extLst (Future Feature Data Storage Area)
};

#endif

