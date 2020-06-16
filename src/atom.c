typedef struct
{
    int id;
    double position[3];
} Atom;

typedef struct
{
    Atom *atoms;
    double basis[3][3];
    int capacity;
    int size;
} AtomCollection;