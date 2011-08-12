#ifndef IRELATIONOBJECTH
#define IRELATIONOBJECTH

#include "cstring.h"

enum ERELTYPE
{
ERT_OFFICEDOCUMENT,
ERT_WORKSHEET,
ERT_SHAREDSTRINGS,
};

class IRelationObject
{
public:
virtual const TString   filename() const = 0;
virtual ERELTYPE        type() const = 0;
virtual int             rid() const = 0;
};

#endif

