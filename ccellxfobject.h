#ifndef CCELLXFOBJECTH
#define CCELLXFOBJECTH

class CCellXFObject;
typedef CCellXFObject TCellXFObject;

#include "cxf.h"

class ITCellXFObjectFromTCellXFs
{
protected:
int     m_id;

public:
        ITCellXFObjectFromTCellXFs();
        ITCellXFObjectFromTCellXFs(const ITCellXFObjectFromTCellXFs& origin);

void    SetId(int id);
int     GetId() const;
void    operator ++ ();
void    operator -- ();

virtual TString save() const = 0;
};

class ITCellXFObjectFromTCellXF
{
protected:
mutable int m_links;

public:
            ITCellXFObjectFromTCellXF();
            ITCellXFObjectFromTCellXF(const ITCellXFObjectFromTCellXF& origin);

void        Link() const;
int         UnLink() const;

virtual int id() const = 0;
};

class CCellXFObject:
    public ITCellXFObjectFromTCellXFs,
    public ITCellXFObjectFromTCellXF,
    protected TXF
{
protected:
typedef TXF base;

using TXF::m_font;
using TXF::m_align;
using TXF::m_fill;
using TXF::m_border;
using TXF::m_numfmt;

//TCellStyleFX    m_cellstylefx;

/* ITCellXFObjectFromTCellXFs */
TString save() const;

/* ITCellXFObjectFromTCellXF */
int id() const;

public:
        CCellXFObject(const TFont& font = TFont(), const TAlignment& align = TAlignment(), const TBorder& border = TBorder(), const TFill& fill = TFill(), const TNumFmt& numfmt = TNumFmt()/*, const TCellStyleFX& cellstylexf*/);
        CCellXFObject(const CCellXFObject& origin);

bool    operator <  (const CCellXFObject& rvalue) const;
};

#endif

