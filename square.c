#include "square.h"

float Square_area(struct Square* self) {
    return (self->length) * (self->length);
}

float vSquare_area(void* vself) {
    return Square_area((struct Square*)vself);
}

void Square_set_id(struct Square* self, int id) {
    self->id = id;
}

int Square_get_id(struct Square* self) {
    return self->id;
}

const struct IShapeAreaFuncs square_ishapearea = {
    .area = vSquare_area
};