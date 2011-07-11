#ifndef CROWOBJECTH
#define CROWOBJECTH

class CRowObject;
typedef CRowObject TRowObject;

#include "cstring.h"
#include "ccell.h"

class CRowObject
{
private:
/* you can't do that */
CRowObject& operator = (const CRowObject&);

protected:
TCells  m_cells;

public:

TCell   operator [] (int index);
TCell   operator [] (const TString& name);
};

#endif

