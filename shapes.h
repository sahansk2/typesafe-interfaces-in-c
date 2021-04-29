struct Square {
    int length;
    int id;
    struct IShapeId const* ishapeid;
};

struct Triangle {
    int base;
    int height;
    int id;
    struct IShapeId const* ishapeid;
};

float Square_area(void* vself);

void Square_set_id(void* vself, int id);

int Square_get_id(void* vself);

float Triangle_area(void* vself); 

void Triangle_set_id(void* vself, int id);

int Triangle_get_id(void* vself);

