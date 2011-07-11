#ifndef CROWH
#define CROWH

#include <map>

class CRow;
typedef CRow TRow;

#include "cstring.h"
#include "crowobject.h"
typedef std::map<int,TRowObject> TRows;

class CRow:
    protected TRows::iterator
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

