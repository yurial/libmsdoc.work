#ifndef CCELLXFH
#define CCELLXFH

class CCellXF;
typedef CCellXF TCellXF;

#include "ccellxfs.h"

class ITCellXFFromTCellObject
{
public:
virtual int id() const = 0;
virtual bool IsSet() const = 0;
};

class CCellXF:
    public ITCellXFFromTCellObject,
    protected TCellXFsContainer::iterator
{
protected:
typedef TCellXFsContainer::iterator base;

ITCellXFsFromTCellXF*   m_cellxfs;

int     id() const;
bool    IsSet() const;

void    Link() const;
void    UnLink() const;

public:
        CCellXF();
        CCellXF(ITCellXFsFromTCellXF& cellxfs, const base& it);
        CCellXF(const CCellXF& origin);
        ~CCellXF();

CCellXF&    operator = (const CCellXF& rvalue);
};

#endif

