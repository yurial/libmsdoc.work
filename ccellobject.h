#ifndef CCELLOBJECTH
#define CCELLOBJECTH

#include <map>

class CCellObject;
typedef CCellObject TCellObject;
typedef std::map<int,TCellObject> TCells;

#include "crowobject.h"
#include "ccellvalue.h"
#include "ccellxf.h"

TString ToStrId(int id);
int     FromStrId(const TString& col);

/*
TODO:
    Attributes:
        cm
        ph
        s
        t
        vm
    Child:
        extLst
*/

class CCellObject:
    protected TCellValue
{
private:

protected:
TRowObject&     m_row;
int             m_id;

TCellXF         m_cellxf;

TString         s() const;

public:
                CCellObject(TRowObject& row, int id);
                ~CCellObject();

using TCellValue::operator =;
CCellObject&    operator = (const TCellXF& cellxf);

int             id() const;
TString         col() const;
TString         cell() const;

int             save(std::stringstream& row) const;
};

#endif

