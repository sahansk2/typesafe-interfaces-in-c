#include <stdio.h>
#include "abstract.h"
#include "shapes.h"

void printArea(void* shape, struct IShapeId const* myshapeid) {
    int id = myshapeid->getid(shape);
    printf("This shape (id=%d) has an area of %f\n", id, myshapeid->area(shape));
    myshapeid->setid(shape, ++id);
}

int main() {
    struct Triangle t = {.id = 3, .base = 4, .height = 17, .ishapeid = &triangle_ishapeid};
    printArea(&t, t.ishapeid);
    printArea(&t, t.ishapeid);
    printArea(&t, t.ishapeid);
}