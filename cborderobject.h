#ifndef CBORDEROBJECTH
#define CBORDEROBJECTH

class CBorderObject;
typedef CBorderObject TBorderObject;

#include "cstring.h"
#include "cborderline.h"

class ITBorderObjectFromTBorders
{
protected:
int     m_id;

public:
        ITBorderObjectFromTBorders();

void    SetId(int id);
int     GetId() const;
void    operator ++ ();
void    operator -- ();

virtual TString save() const = 0;
};

class ITBorderObjectFromTBorder
{
protected:
mutable int m_links;

public:
            ITBorderObjectFromTBorder();

void        Link() const;
int         UnLink() const;

virtual int id() const = 0;
};

class CBorderObject:
    public ITBorderObjectFromTBorders,
    public ITBorderObjectFromTBorder
{
protected:
TBorderLine     m_left;
TBorderLine     m_right;
TBorderLine     m_top;
TBorderLine     m_bottom;
TBorderLine     m_diagonal;
bool            m_down;
bool            m_up;
bool            m_outline;

bool            IsSet() const;
/* ITBorderObjectFromTBorders */
TString         save() const;

/* ITBorderObjectFromTBorder */
int             id() const;

public:
                CBorderObject();
                CBorderObject(const TBorderLine& left,
                              const TBorderLine& right,
                              const TBorderLine& top, 
                              const TBorderLine& bottom, 
                              const TBorderLine& diagonal, 
                              bool down,
                              bool up,
                              bool outline);

bool            operator <  (const CBorderObject& rvalue) const;
};

#endif

