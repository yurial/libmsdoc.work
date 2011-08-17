#ifndef CCELLOBJECTH
#define CCELLOBJECTH

#include <map>

class CCellObject;
typedef CCellObject TCellObject;
typedef std::map<int,TCellObject> TCells;

#include "crowobject.h"
#include "ccellvalue.h"

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

int             id() const;
TString         col() const;
TString         cell() const;

public:
                CCellObject(TRowObject& row, int id);
                ~CCellObject();

using TCellValue::operator =;

int             save(std::stringstream& row) const;
};

#endif

