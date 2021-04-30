#include "ishapearea.h"
#include "square.h"
#include "triangle.h"
#include "house.h"

int test_triangle_area() {
    struct Triangle t = {.id = 3, .base = 4, .height = 17};
    Triangle_SETUP_INTERFACE(&t);
    return 34 == Triangle_area(&t);
}

int test_square_area() {
    struct Square s = {.id = -10, .length = 2};
    Square_SETUP_INTERFACE(&s);
    return 4 == Square_area(&s);
}

int test_interface() {
    return 1;
}