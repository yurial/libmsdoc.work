#include "crowobject.h"

CRowObject::CRowObject(int id):
    m_id( id )
{
}

int CRowObject::id() const
{
return m_id;
}

int CRowObject::row() const
{
return m_id + 1;
}

TCell CRowObject::operator [] (int index)
{
std::pair<TCells::iterator,bool> result = m_cells.insert( std::make_pair( index, TCellObject( *this, index ) ) );
return result.first;
}

TCell CRowObject::operator [] (const TString& name)
{
return operator [] ( FromStrId( name ) );
}

int CRowObject::save(std::stringstream& sheet) const
{
sheet << "<row r=\"" << row() << "\">";
//cells
TCells::const_iterator it = m_cells.begin();
TCells::const_iterator end = m_cells.end();
for (; it != end; ++it)
    {
    it->second.save( sheet );
    //TODO: ret
    }

sheet << "</row>\n";
return 0;
}

