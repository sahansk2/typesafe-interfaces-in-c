#include <stdio.h>
#include "ishapearea.h"
#include "square.h"
#include "triangle.h"
#include "house.h"

void printArea(struct IShapeArea const* ishape) {
    printf("This shape has an area of %f\n", ishape->funcs->area(ishape->vself));
}

int compareArea(struct IShapeArea const* ishape1, struct IShapeArea const* ishape2) {
    float area1 = ishape1->funcs->area(ishape1->vself);
    float area2 = ishape2->funcs->area(ishape2->vself);
    if (area1 < area2) {
        return -1;
    } else if (area1 == area2) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    struct Triangle t = {.id = 3, .base = 4, .height = 17};
    Triangle_SETUP_INTERFACE(&t);
    struct Square v = {.id = -10, .length = 2};
    Square_SETUP_INTERFACE(&v);
    struct House h = {.roof = t, .body = v};
    House_SETUP_INTERFACE(&h);

    printArea(&t.ishapearea);
    printArea(&v.ishapearea);
    printArea(&h.ishapearea);

    if (compareArea(&t.ishapearea, &v.ishapearea)) {
        printf("t and v have inequal areas!\n");
    }

    if (!compareArea(&t.ishapearea, &t.ishapearea)) {
        printf("t and t have same areas!\n");
    }

}