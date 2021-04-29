#ifndef SQUARE_H
#define SQUARE_H
#include "ishapearea.h"

struct Square {
    int length;
    int id;
    struct IShapeArea ishapearea;
};

float Square_area(struct Square* self);
float vSquare_area(void* vself);

void Square_set_id(struct Square* self, int id);

int Square_get_id(struct Square* self);

extern const struct IShapeAreaFuncs square_ishapearea;

static inline void Square_SETUP_INTERFACE(struct Square* self) {
    self->ishapearea.vself = self;
    self->ishapearea.funcs = &square_ishapearea;
}
#endif