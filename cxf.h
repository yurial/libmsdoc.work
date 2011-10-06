#ifndef CXFH
#define CXFH

class CXF;
typedef CXF TXF;

#include "cfont.h"
#include "calignment.h"
#include "cfill.h"
#include "cborder.h"
#include "cnumfmt.h"

class CXF
{
protected:
TAlignment  m_align;    //(§18.8.1  )
TFont       m_font;     //(§18.18.32)
TFill       m_fill;     //(§18.18.30)
TBorder     m_border;   //(§18.18.2 )
//extLst (Future Feature Data Storage Area) §18.2.10
//protection (Protection Properties) §18.8.33
TNumFmt     m_numfmt;   //numFmtId (§18.18.47)
//pivotButton
//quotePrefix
//xfId (Format Id) (§18.18.10)

public:
        CXF();
        CXF(const TFont& font = TFont(), const TAlignment& align = TAlignment(), const TBorder& border = TBorder(), const TFill& fill = TFill(), const TNumFmt& numfmt = TNumFmt());

bool    operator <  (const CXF& rvalue) const;
};

#endif

