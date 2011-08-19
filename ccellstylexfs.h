#ifndef CCELLSTYLEXFSH
#define CCELLSTYLEXFSH

#include <set>

class CCellStyleXFs;
typedef CCellStyleXFs TCellStyleXFs;
typedef TCellStyleXFs TCellStyle;

#include "cxf.h"

typedef std::set<TXF> TCellStyleXFContainet;

class CCellStyleXfs:
    protected TCellStyleXFContainet
{
protected:

public:

};

#endif

