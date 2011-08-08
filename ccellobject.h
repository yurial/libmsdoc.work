#ifndef CCELLOBJECTH
#define CCELLOBJECTH

#include <map>

class CCellObject;
typedef CCellObject TCellObject;
typedef std::map<int,TCellObject> TCells;

#include "crowobject.h"
#include "csharedstring.h"

TString ToStrId(int id);
int     FromStrId(const TString& col);

class CCellObject
{
private:

protected:
TRowObject&     m_row;
int             m_id;
TSharedString*  m_shastr;
TString*        m_str;

public:
                CCellObject(TRowObject& row, int id);
                ~CCellObject();

int             id() const;
TString         col() const;
TString         cell() const;

CCellObject&    operator = (const TString& str);
CCellObject&    operator = (const TSharedString& str);

int             save(std::stringstream& row) const;
};

#endif

