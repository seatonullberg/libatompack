#include <string.h>
#include "atom.h"

Atom atom_new(int id, double position[3])
{
    Atom atom;
    memcpy(&atom.id, &id, sizeof(int));
    memcpy(&atom.position, position, sizeof(double) * 3);
    return atom;
}

int atom_get_id(Atom *atom)
{
    return atom->id;
}

void atom_set_id(Atom *atom, int id)
{
    memcpy(&atom->id, &id, sizeof(int));
}

double *atom_get_position(Atom *atom)
{
    return atom->position;
}

void atom_set_position(Atom *atom, double position[3])
{
    memcpy(&atom->position, position, sizeof(double) * 3);
}

AtomCollection atom_collection_new(double basis[3][3], size_t size, size_t capacity, Atom *atoms[])
{
    AtomCollection collection;
    memcpy(&collection.basis, basis, sizeof(double) * 3 * 3);
    memcpy(&collection.size, &size, sizeof(size_t));
    memcpy(&collection.capacity, &capacity, sizeof(size_t));
    memcpy(&collection.atoms, atoms, sizeof(Atom *));
    return collection;
}