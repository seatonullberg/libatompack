#include <stdlib.h>
#include <string.h>
#include "atom.h"

Atom *atom_new(int id, double position[3])
{
    Atom *ptr = malloc(sizeof(Atom));
    atom_set_id(ptr, id);
    atom_set_position(ptr, position);
    return ptr;
}

void atom_free(Atom *ptr)
{
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

void atom_get_position(Atom *ptr, double out[3])
{
    for (int i = 0; i < 3; i++)
    {
        out[i] = ptr->position[i];
    }
}

void atom_set_position(Atom *ptr, double position[3])
{
    for (int i = 0; i < 3; i++)
    {
        ptr->position[i] = position[i];
    }
}

AtomCollection *atom_collection_new(double basis[3][3], size_t length, size_t capacity, Atom *atoms[])
{
    size_t size = 0;
    size += sizeof(double) * 3 * 3;
    size += sizeof(size_t) * 3;
    size += sizeof(Atom *) * capacity;
    AtomCollection *ptr = malloc(size);
    ptr->size = size;
    ptr->length = length;
    ptr->capacity = capacity;
    atom_collection_set_basis(ptr, basis);
    atom_collection_set_atoms(ptr, length, capacity, atoms);
    return ptr;
}

void atom_collection_free(AtomCollection *ptr)
{
    for (int i = 0; i < ptr->length; i++)
    {
        atom_free(ptr->atoms[i]);
    }
    free(ptr);
}

void atom_collection_get_basis(AtomCollection *ptr, double out[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            out[i][j] = ptr->basis[i][j];
        }
    }
}

void atom_collection_set_basis(AtomCollection *ptr, double basis[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ptr->basis[i][j] = basis[i][j];
        }
    }
}

void atom_collection_get_atoms(AtomCollection *ptr, Atom *out[])
{
    for (int i = 0; i < ptr->length; i++)
    {
        out[i] = ptr->atoms[i];
    }
}

void atom_collection_set_atoms(AtomCollection *ptr, size_t length, size_t capacity, Atom *atoms[])
{
    if (capacity > ptr->capacity)
    {
        size_t size = ptr->size + (capacity * sizeof(Atom *));
        ptr = realloc(ptr, size);
        ptr->size = size;
    }
    // clear all existing pointers
    for (int i = 0; i < ptr->length; i++)
    {
        atom_free(ptr->atoms[i]);
    }
    // assign new pointers
    for (int i = 0; i < length; i++)
    {
        ptr->atoms[i] = atoms[i];
    }
    ptr->length = length;
    ptr->capacity = capacity;
}