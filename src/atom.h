typedef struct
{
    int id;
    double position[3];
} Atom;

Atom *atom_new(int id, double position[3]);
void atom_free(Atom *atom);
int atom_get_id(Atom *atom);
void atom_set_id(Atom *atom, int value);
void atom_get_position(Atom *ptr, double out[3]);
void atom_set_position(Atom *atom, double position[3]);

typedef struct
{
    double basis[3][3];
    size_t length;
    size_t capacity;
    size_t size;
    Atom *atoms[];
} AtomCollection;

AtomCollection *atom_collection_new(double basis[3][3], size_t length, size_t capacity, Atom *atoms[]);
void atom_collection_free(AtomCollection *collection);
void atom_collection_get_basis(AtomCollection *ptr, double out[3][3]);
void atom_collection_set_basis(AtomCollection *ptr, double basis[3][3]);
void atom_collection_get_atoms(AtomCollection *ptr, Atom *out[]);
void atom_collection_set_atoms(AtomCollection *ptr, size_t length, size_t capacity, Atom *atoms[]);