#include "house.h"

float House_area(struct House *self) {
    float roof_area = self->roof.ishapearea.funcs->area(self->roof.ishapearea.vself);
    float body_area = self->body.ishapearea.funcs->area(self->body.ishapearea.vself);
    return roof_area + body_area;
}

float vHouse_area(void* vself) {
    return House_area((struct House*)vself);
}

const struct IShapeAreaFuncs house_ishapearea = {
    .area = vHouse_area
};