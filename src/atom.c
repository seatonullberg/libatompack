#include <stdlib.h>
#include <string.h>
#include "atom.h"

Atom *atom_new(int id, double position[3])
{
    Atom *ptr = malloc(sizeof(Atom));
    ptr->id = id;
    for (int i = 0; i < 3; i++) {
        ptr->position[i] = position[i];
    }
    return ptr;
}

void atom_free(Atom *ptr) {
    free(ptr);
}

int atom_get_id(Atom *ptr)
{
    return ptr->id;
}

void atom_set_id(Atom *ptr, int id)
{
    ptr->id = id;
}

double *atom_get_position(Atom *ptr)
{
    return ptr->position;
}

void atom_set_position(Atom *ptr, double position[3])
{
    for (int i = 0; i < 3; i++) {
        ptr->position[i] = position[i];
    }
}

AtomCollection *atom_collection_new(double basis[3][3], size_t length, size_t capacity, Atom *atoms[]) {
    size_t size = 0;
    size += sizeof(double) * 3 * 3;
    size += sizeof(size_t) * 2;
    size += sizeof(Atom *) * capacity;
    AtomCollection *ptr = malloc(size);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ptr->basis[i][j] = basis[i][j];
        }
    }
    ptr->length = length;
    ptr->capacity = capacity;
    for (int i = 0; i < length; i++) {
        ptr->atoms[i] = atoms[i];
    }
    return ptr;
}

void atom_collection_free(AtomCollection *ptr) {
    for (int i = 0; i < ptr->length; i++) {
        atom_free(ptr->atoms[i]);
    }
    free(ptr);
}