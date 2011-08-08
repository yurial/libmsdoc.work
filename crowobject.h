#ifndef CROWOBJECTH
#define CROWOBJECTH

#include <sstream>
#include <map>

class CRowObject;
typedef CRowObject TRowObject;
typedef std::map<int,TRowObject> TRows;

#include "cstring.h"
#include "ccell.h"

class CRowObject
{
private:
/* you can't do that */
CRowObject& operator = (const CRowObject&);

protected:
int     m_id;
TCells  m_cells;

public:
        CRowObject(int id);
int     id() const;
int     row() const;
TCell   operator [] (int index);
TCell   operator [] (const TString& name);

int     save(std::stringstream& sheet) const;
};

#endif

