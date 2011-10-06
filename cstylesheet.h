#ifndef CSTYLESHEETH
#define CSTYLESHEETH

class CStyleSheet;
typedef CStyleSheet TStyleSheet;

#include "cbaserelationshipobject.h"
#include "cnumfmts.h"
#include "cfonts.h"
#include "cfills.h"
#include "cborders.h"
//#include "ccellstylexfs.h"
#include "ccellxfs.h"

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
TString         m_dir;

const TString   filename() const;
ECONTENTTYPE    type() const;

int             save(TZip& archive, TContent& content) const;

public:
                CStyleSheet(const TString& dir, TRelationShips& relationships);

TNumFmts        m_numfmts;
TFonts          m_fonts;
TFills          m_fills;
TBorders        m_borders;
//dxfs
TCellXFs        m_cellxfs;
//cellStyles (Cell Styles)
//TCellStyleXFs   m_cellstylexfs;//cellStyleXfs (Formatting Records)
//tableStyles (Table Styles)
//colors (Colors)
//extLst (Future Feature Data Storage Area)
};

#endif

