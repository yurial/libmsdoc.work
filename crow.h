#ifndef CROWH
#define CROWH

#include <sstream>

class CRow;
typedef CRow TRow;

#include "cstring.h"
#include "crowobject.h"

class CRow:
    public TRows::iterator
{
private:
/* you can't do that */
CRow&   operator = (const CRow&);

protected:
typedef TRows::iterator base;
using base::operator ->;

public:
        CRow(const base& it);

TCell   operator [] (int index);
TCell   operator [] (const TString& name);
};

#endif

