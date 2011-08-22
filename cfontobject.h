#ifndef CFONTOBJECTH
#define CFONTOBJECTH

class CFontObject;
typedef CFontObject TFontObject;

#include "cstring.h"
#include "cfontflags.h"

class ITFontObjectFromTFonts
{
protected:
int     m_id;

public:
        ITFontObjectFromTFonts();
        ITFontObjectFromTFonts(const ITFontObjectFromTFonts& origin);

void    SetId(int id);
int     GetId() const;
void    operator ++ ();
void    operator -- ();

virtual TString save() const = 0;
};

class ITFontObjectFromTFont
{
protected:
mutable int m_links;

public:
            ITFontObjectFromTFont();
            ITFontObjectFromTFont(const ITFontObjectFromTFont& origin);

void        Link() const;
int         UnLink() const;

virtual int id() const = 0;
};

class CFontObject:
    public ITFontObjectFromTFonts,
    public ITFontObjectFromTFont
{
protected:
TString     m_name;     //name (Font Name) 18.8.29
int         m_size;     //sz (Font Size) 18.4.11
TFontFlags  m_flags;
//TODO: TFontCharset    //charset (Character Set) 18.4.1
//TODO: TColor          //color (Data Bar Color) 18.3.1.15
//TODO: TFontFamily     //family (Font Family) 18.8.18
//TODO: TFontScheme     //scheme (Scheme) 18.8.35
//TODO: TVertalign      /vertAlign (Vertical Alignment) 18.4.14

/* ITFontObjectFromTFonts */
TString     save() const;

/* ITFontObjectFromTFont */
int         id() const;

public:
            CFontObject();
            CFontObject(TString name, int size, TFontFlags flags);
            CFontObject(const CFontObject& origin);

bool        operator <  (const CFontObject& rvalue) const;
};

#endif

