#ifndef CALIGNMENTH
#define CALIGNMENTH

#include "cstring.h"

typedef unsigned int uint;
class CAlignment;
typedef CAlignment TAlignment;

enum EHORIZONTAL
{
EHORIZONTAL_GENERAL,
EHORIZONTAL_CENTER,
EHORIZONTAL_CENTERCONTINOUS,
EHORIZONTAL_DISTRIBUTED,
EHORIZONTAL_FILL,
EHORIZONTAL_JUSTIFY,
EHORIZONTAL_LEFT,
EHORIZONTAL_RIGHT,
};

enum EVERTICAL
{
EVERTICAL_BOTTOM,
EVERTICAL_CENTER,
EVERTICAL_DISTRIBUTED,
EVERTICAL_JUSTIFY,
EVERTICAL_TOP,
};

class CAlignment //#18.8.1
{
protected:
EHORIZONTAL m_horizontal;
EVERTICAL   m_vertical;
bool        m_wrap;
bool        m_shrink;
uint        m_rotation;
int         m_indent;
//bool justifyLastLine,
//int readingOrder,
//int relativeIndent,

public:
            CAlignment(EHORIZONTAL horizontal = EHORIZONTAL_GENERAL, EVERTICAL vertical = EVERTICAL_BOTTOM, bool wrap = false, bool shrink = false, uint rotation = 0, int indent = 0);

TString     save(const TString& tag = "alignment") const;

bool        operator <  (const CAlignment& rvalue) const;
};

#endif

