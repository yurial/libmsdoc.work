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
//using TXF::m_alignment;
//using TXF::m_fill;
//using TXF::m_border;
//using TXF::m_numfmt;

//TCellStyleFX    m_cellstylefx;

/* ITCellXFObjectFromTCellXFs */
TString save() const;

/* ITCellXFObjectFromTCellXF */
int id() const;

public:
        CCellXFObject();
        CCellXFObject(const TFont& font/*,const TAlignment& align*//*,const TFill& fill*//*,const TBorder& border*//*,const TNumFmt& numfmt*//*,TCellStyleFX*/);
        CCellXFObject(const CCellXFObject& origin);

bool    operator <  (const CCellXFObject& rvalue) const;
};

#endif

