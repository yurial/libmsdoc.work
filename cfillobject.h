#ifndef CFILLOBJECTH
#define CFILLOBJECTH

class CFillObject;
typedef CFillObject TFillObject;

#include "cstring.h"
#include "cgradientfill.h"
#include "cpatternfill.h"

class ITFillObjectFromTFills
{
protected:
int     m_id;

public:
        ITFillObjectFromTFills();
        ITFillObjectFromTFills(const ITFillObjectFromTFills& origin);

void    SetId(int id);
int     GetId() const;
void    operator ++ ();
void    operator -- ();

virtual TString save() const = 0;
};

class ITFillObjectFromTFill
{
protected:
mutable int m_links;

public:
            ITFillObjectFromTFill();
            ITFillObjectFromTFill(const ITFillObjectFromTFill& origin);

void        Link() const;
int         UnLink() const;

virtual int id() const = 0;
};

enum EFILLTYPE
{
EFILL_NONE,
EFILL_GRADIENT, //gradientFill (Gradient) §18.8.24
EFILL_PATTERN,  //patternFill (Pattern) §18.8.32
};

class CFillObject:
    public ITFillObjectFromTFills,
    public ITFillObjectFromTFill
{
protected:
EFILLTYPE   m_type;
void*       m_object;

void        clear();

/* ITFillObjectFtomTFills */
TString     save() const;

/* ITFillObjectFromTFill */
int         id() const;

public:
            CFillObject();
            CFillObject(const CFillObject& origin);
            CFillObject(const TGradientFill& fill);
            CFillObject(const TPatternFill& fill);
            ~CFillObject();

bool        operator <  (const CFillObject& rvalue) const;
};

#endif

