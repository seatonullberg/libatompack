typedef struct
{
    int id;
    double position[3];
} Atom;

Atom *atom_new(int id, double position[3]);
void atom_free(Atom *atom);
int atom_get_id(Atom *atom);
void atom_set_id(Atom *atom, int value);
double *atom_get_position(Atom *atom);
void atom_set_position(Atom *atom, double position[3]);

typedef struct
{
    double basis[3][3];
    size_t length;
    size_t capacity;
    Atom *atoms[];
} AtomCollection;

AtomCollection *atom_collection_new(double basis[3][3], size_t length, size_t capacity, Atom *atoms[]);
void atom_collection_free(AtomCollection *collection);