#include "abstract.h"
#include "shapes.h"

float Square_area(void* vself) {
    struct Square* self = vself;
    return (self->length) * (self->length) * (self->id);
}

void Square_set_id(void* vself, int id) {
    struct Square* self = vself;
    self->id = id;
}

int Square_get_id(void* vself) {
    struct Square* self = vself;
    return self->id;
}

const struct IShapeId triangle_ishapeid = {
    .area = Triangle_area,
    .setid = Triangle_set_id,
    .getid = Triangle_get_id
};

float Triangle_area(void* vself) {
    struct Triangle* self = vself;
    return (0.5f) * (self->base) * (self->height);
}

void Triangle_set_id(void* vself, int id) {
    struct Triangle* self = vself;
    self->id = id;
}

int Triangle_get_id(void* vself) {
    struct Triangle* self = vself;
    return self->id;
}

const struct IShapeId square_ishapeid = {
    .area = Square_area,
    .setid = Square_set_id,
    .getid = Square_get_id
};
