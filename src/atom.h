#include <string.h>

typedef struct
{
    int id;
    double position[3];
} Atom;

Atom atom_new(int id, double position[3]);

typedef struct
{
    double basis[3][3];
    size_t size;
    size_t capacity;
    Atom *atoms[];
} AtomCollection;

AtomCollection atom_collection_new(double basis[3][3], size_t size, size_t capacity, Atom *atoms[]);