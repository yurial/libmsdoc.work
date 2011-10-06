#ifndef CCELLSTYLEXFSH
#define CCELLSTYLEXFSH

#include <set>

class CCellXFs;
typedef CCellXFs TCellXFs;
typedef TCellXFs TCellStyle;

#include "ccellxfobject.h"
typedef std::set<TCellXFObject> TCellXFsContainer;

class ITCellXFsFromTStyleSheet
{
public:
virtual TString save() const = 0;
};

class ITCellXFsFromTCellXF
{
public:
virtual void erase(TCellXFsContainer::iterator& cellfx) = 0;
};

#include "ccellxf.h"

class CCellXFs:
    public ITCellXFsFromTCellXF,
    public ITCellXFsFromTStyleSheet,
    protected TCellXFsContainer
{
private:
/* you can't do that */
            CCellXFs(const CCellXFs& origin);
CCellXFs&   operator = (const CCellXFs& rvalue);

protected:
typedef TCellXFsContainer base;

/* ITCellXFsFromTStyleSheet */
TString     save() const;
/* ITCellXFsFromTCellXF */
void        erase(base::iterator& cellfx);

public:
            CCellXFs();
TCellXF     insert(const TFont& font = TFont(), const TAlignment& align = TAlignment(), const TBorder& border = TBorder(), const TFill& fill = TFill(), const TNumFmt& numfmt = TNumFmt()/*, const TCellStyle& cellstyle*/);
};

#endif

