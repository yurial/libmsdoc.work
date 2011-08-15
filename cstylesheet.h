#ifndef CSTYLESHEETH
#define CSTYLESHEETH

class CStyleSheet;
typedef CStyleSheet TStyleSheet;

#include "crelationsheeps.h"

class CStyleSheet:
    public IRelationObject
{
protected:
TString             m_dir;
TRelationSheeps&    m_relationsheeps;
TRelationSheep      m_relationsheep;

const TString       filename() const;
ERELTYPE            type() const;
int                 rid() const;

public:
                    CStyleSheet(const TString& dir, TRelationShips& relationships);
int                 save(TZip& archive, TContent& content) const;

//TFontStyles     //fonts
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

