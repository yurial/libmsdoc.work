#ifndef CCELLSTYLEXFSH
#define CCELLSTYLEXFSH

#include <set>

class CCellStyleXFs;
typedef CCellStyleXFs TCellStyleXFs;
typedef TCellStyleXFs TCellStyle;

#include "cxf.h"

typedef std::set<TXF> TCellStyleXFContainer;

class CCellStyleXfs:
    protected TCellStyleXFContainer
{
protected:

public:

};

#endif

