struct IShapeId {
    float (*area)(void* vself);
    void (*setid)(void* vself, int id);
    int (*getid)(void* vself);
};

extern const struct IShapeId square_ishapeid;
extern const struct IShapeId triangle_ishapeid;