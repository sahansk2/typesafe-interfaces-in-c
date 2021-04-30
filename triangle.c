#include "triangle.h"

float Triangle_area(struct Triangle* self) {
    return (0.5f) * (self->base) * (self->height);
}
float _Triangle_area(void* vself) {
    return Triangle_area((struct Triangle*)vself);
}

void Triangle_set_id(struct Triangle* self, int id) {
    self->id = id;
}

int Triangle_get_id(struct Triangle* self) {
    return self->id;
}

const struct IShapeAreaFuncs triangle_ishapearea = {
    .area = _Triangle_area
};