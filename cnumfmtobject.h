#ifndef CNUMFMTOBJECTH
#define CNUMFMTOBJECTH

enum ENUMFMT
{
ENUMFMT_GENERAL,
ENUMFMT_1,
ENUMFMT_2,
ENUMFMT_3,
ENUMFMT_4,
ENUMFMT_5,
ENUMFMT_6,
ENUMFMT_7,
ENUMFMT_8,
ENUMFMT_9,
ENUMFMT_10,
ENUMFMT_11,
ENUMFMT_12,
ENUMFMT_13,
ENUMFMT_14,
ENUMFMT_15,
ENUMFMT_16,
ENUMFMT_17,
ENUMFMT_18,
ENUMFMT_19,
ENUMFMT_20,
ENUMFMT_21,
ENUMFMT_22,
ENUMFMT_23,
ENUMFMT_24,
ENUMFMT_25,
ENUMFMT_26,
ENUMFMT_27,
ENUMFMT_28,
ENUMFMT_29,
ENUMFMT_30,
ENUMFMT_31,
ENUMFMT_32,
ENUMFMT_33,
ENUMFMT_34,
ENUMFMT_35,
ENUMFMT_36,
ENUMFMT_37,
ENUMFMT_38,
ENUMFMT_39,
ENUMFMT_40,
ENUMFMT_41,
ENUMFMT_42,
ENUMFMT_43,
ENUMFMT_44,
ENUMFMT_45,
ENUMFMT_46,
ENUMFMT_47,
ENUMFMT_48,
ENUMFMT_49,
ENUMFMT_50,
ENUMFMT_51,
ENUMFMT_52,
ENUMFMT_53,
ENUMFMT_54,
ENUMFMT_55,
ENUMFMT_56,
ENUMFMT_57,
ENUMFMT_58,
ENUMFMT_59,
ENUMFMT_60,
ENUMFMT_61,
ENUMFMT_62,
ENUMFMT_63,
ENUMFMT_64,
ENUMFMT_65,
ENUMFMT_66,
ENUMFMT_67,
ENUMFMT_68,
ENUMFMT_69,
ENUMFMT_70,
ENUMFMT_71,
ENUMFMT_72,
ENUMFMT_73,
ENUMFMT_74,
ENUMFMT_75,
ENUMFMT_76,
ENUMFMT_77,
ENUMFMT_78,
ENUMFMT_79,
ENUMFMT_80,
ENUMFMT_81,
ENUMFMT_82,
ENUMFMT_83,
ENUMFMT_84,
ENUMFMT_85,
ENUMFMT_86,
ENUMFMT_87,
ENUMFMT_88,
ENUMFMT_89,
ENUMFMT_90,
ENUMFMT_91,
ENUMFMT_92,
ENUMFMT_93,
ENUMFMT_94,
ENUMFMT_95,
ENUMFMT_96,
ENUMFMT_97,
ENUMFMT_98,
ENUMFMT_99,
ENUMFMT_100,
ENUMFMT_101,
ENUMFMT_102,
ENUMFMT_103,
ENUMFMT_104,
ENUMFMT_105,
ENUMFMT_106,
ENUMFMT_107,
ENUMFMT_108,
ENUMFMT_109,
ENUMFMT_110,
ENUMFMT_111,
ENUMFMT_112,
ENUMFMT_113,
ENUMFMT_114,
ENUMFMT_115,
ENUMFMT_116,
ENUMFMT_117,
ENUMFMT_118,
ENUMFMT_119,
ENUMFMT_120,
ENUMFMT_121,
ENUMFMT_122,
ENUMFMT_123,
ENUMFMT_124,
ENUMFMT_125,
ENUMFMT_126,
ENUMFMT_127,
};

class CNumFmtObject;
typedef CNumFmtObject TNumFmtObject;

#include "cstring.h"

class ITNumFmtObjectFromTNumFmts
{
protected:
int     m_id;

public:
        ITNumFmtObjectFromTNumFmts();
        ITNumFmtObjectFromTNumFmts(const ITNumFmtObjectFromTNumFmts& origin);

void    SetId(int id);
int     GetId() const;
void    operator ++ ();
void    operator -- ();

virtual TString save() const = 0;
};

class ITNumFmtObjectFromTNumFmt
{
protected:
mutable int m_links;

public:
            ITNumFmtObjectFromTNumFmt();
            ITNumFmtObjectFromTNumFmt(const ITNumFmtObjectFromTNumFmt& origin);

void        Link() const;
int         UnLink() const;

virtual int id() const = 0;
};

class CNumFmtObject:
    public ITNumFmtObjectFromTNumFmts,
    public ITNumFmtObjectFromTNumFmt
{
protected:
TString     m_fmt;

/* ITNumFmtObjectFromTTNumFmts */
TString     save() const;

/* ITNumFmtObjectFromTNumFmt */
int         id() const;

public:
            CNumFmtObject(ENUMFMT fmt);
            CNumFmtObject(TString fmt);
            CNumFmtObject(const CNumFmtObject& origin);

bool        operator < (const CNumFmtObject& rvalue) const;
};

#endif

