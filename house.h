#ifndef HOUSE_H
#define HOUSE_H

#include "ishapearea.h"
#include "square.h"
#include "triangle.h"

struct House {
    struct Square body;
    struct Triangle roof;
    struct IShapeArea ishapearea;
};

float House_area(struct House *self);
float _House_area(void* vself);

extern const struct IShapeAreaFuncs house_ishapearea;

static inline void House_SETUP_INTERFACE(struct House *self) {
    self->ishapearea.vself = self;
    self->ishapearea.funcs = &house_ishapearea;
}

#endif