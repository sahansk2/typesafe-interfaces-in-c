#ifndef ISHAPEAREA_H
#define ISHAPEAREA_H
struct IShapeAreaFuncs {
    float (*area)(void* vself);
};

struct IShapeArea {
    void* vself;
    struct IShapeAreaFuncs const* funcs;
};

#endif