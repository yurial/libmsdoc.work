#ifndef CFONTFLAGS
#define CFONTFLAGS

enum EFONTFLAG
{
EFF_NONE        = 0x00,
EFF_BOLD        = 0x01, // $18.8.2
EFF_CODENSE     = 0x02, // $18.8.12
EFF_EXTEND      = 0x04, // $18.8.17
EFF_ITALIC      = 0x08, // $18.8.26
EFF_OUTLINE     = 0x10, // $18.4.2
EFF_SHADOW      = 0x20, // $18.8.36
EFF_STRIKE      = 0x40, // $18.4.10
EFF_UNDERLINE   = 0x80, // $18.4.13
};

class CFontFlags;
typedef CFontFlags TFontFlags;

#include "cstring.h"

class ITFontFlagsFromTFontObject
{
public:
virtual TString save() const = 0;
};

class CFontFlags:
    public ITFontFlagsFromTFontObject
{
protected:
int         m_flags;

TString     save() const;

public:
            CFontFlags();
            CFontFlags(int flags);
            CFontFlags(EFONTFLAG flag);

bool        operator <  (const CFontFlags& rvalue) const;

CFontFlags& operator =  (const CFontFlags& rvalue);
CFontFlags& operator =  (int flags);
CFontFlags& operator =  (EFONTFLAG flag);
CFontFlags& operator |= (const CFontFlags& rvalue);
CFontFlags& operator |= (int flags);
CFontFlags& operator |= (EFONTFLAG flag);
};

#endif

