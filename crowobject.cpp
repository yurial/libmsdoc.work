#include "crowobject.h"

TCell CRowObject::operator [] (int index)
{
std::pair<TCells::iterator,bool> result = m_cells.insert( std::make_pair( index, TCellObject() ) );
return result.first;
}

TCell CRowObject::operator [] (const TString& name)
{
int index = 0;
int power = 1;
for (int pos = name.size() - 1; 0 <= pos; --pos, power *= ('Z' - 'A') )
    {
    register int value = name[ pos ] - 'A';
    value *= power;
    index += power;
    }
return operator [] ( index );
}

