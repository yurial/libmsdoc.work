#ifndef CGRADIENTFILLH
#define CGRADIENTFILLH

class CGradientFill;
typedef CGradientFill TGradientFill;

#include "cstring.h"

class ITGradientFillFromTFillObject
{
public:
virtual TString save() const = 0;
virtual bool operator <  (const CGradientFill& rvalue) const = 0;
};

class CGradientFill:
    public ITGradientFillFromTFillObject
{
protected:
//gradientstop
//bottom (BottomConvergence)
//degree (LinearGradient Degree)
//left (LeftConvergence)
//right (RightConvergence)
//top (Top GradientConvergence)
//type (Gradient FillType)

/* ITGradientFillFromTFillObject */
TString save() const;
bool    operator <  (const CGradientFill& rvalue) const;
public:
        CGradientFill();

};

#endif

