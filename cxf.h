#ifndef CXFH
#define CXFH

class CXF;
typedef CXF TXF;

#include "cfont.h"
#include "cfill.h"

class CXF
{
protected:
//alignment (Alignment)   //§18.8.1
//extLst (Future Feature Data Storage Area) §18.2.10
//protection (Protection Properties) §18.8.33
//BorderId (BorderId) (§18.18.2)
TFont  m_font;  //(§18.18.32)
TFill  m_fill;  //(§18.18.30)
//numFmtId (§18.18.47)
//pivotButton
//quotePrefix
//xfId (Format Id) (§18.18.10)

public:
        CXF();
        CXF(const TFont& font/*,const TAlignment& align*/, const TFill& fill/*, const TBorder& border*//*, const TNumFmt& numfmt*/);

bool    operator <  (const CXF& rvalue) const;
};

#endif

