#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "ishapearea.h"

struct Triangle {
    int base;
    int height;
    int id;
    struct IShapeArea ishapearea;
};

float Triangle_area(struct Triangle* self); 
float vTriangle_area(void* vself); 

void Triangle_set_id(struct Triangle* self, int id);

int Triangle_get_id(struct Triangle* self);

extern const struct IShapeAreaFuncs triangle_ishapearea;

static inline void Triangle_SETUP_INTERFACE(struct Triangle* self){
    self->ishapearea.vself = self;
    self->ishapearea.funcs = &triangle_ishapearea;
}

#endif