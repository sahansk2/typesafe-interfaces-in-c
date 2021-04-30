#include "house.h"

float House_area(struct House *self) {
    float roof_area = Triangle_area(&self->roof);
    float body_area = Square_area(&self->body);
    return roof_area + body_area;
}

float _House_area(void* vself) {
    return House_area((struct House*)vself);
}

const struct IShapeAreaFuncs house_ishapearea = {
    .area = _House_area
};