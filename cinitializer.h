#ifndef CINITIALIZERH
#define CINITIALIZERH

typedef void (*INIT_FUNC)();

class CInitializer
{
public:
    CInitializer(INIT_FUNC func)
    {
    func();
    }
};

typedef CInitializer TInitializer;

#endif

