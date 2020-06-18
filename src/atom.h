/**
 * @file
 * @brief This file contains low level primitives for building atomic structures.
*/

/**
 * Primitive representation of an atom.
 * 
 * @param id ID used to map the `Atom` to a larger database of atomic properties.
 * @param position 3D coordinate indicating the location of the `Atom`.
*/
typedef struct
{
    int id;
    double position[3];
} Atom;

/**
 * Returns a pointer to an initialized `Atom`.
 *
 * @param id ID used to map the `Atom` to a larger database of atomic properties.
 * @param position 3D coordinate indicating the location of the `Atom`.
*/
Atom *atom_new(int id, double position[3]);

/**
 * Frees the memory associated with an `Atom`.
 * 
 * @param ptr A pointer to an `Atom`.
*/
void atom_free(Atom *ptr);

/**
 * Returns the `id` parameter.
 * 
 * @param ptr A pointer to an `Atom`.
*/
int atom_get_id(Atom *ptr);

/**
 * Sets a new value for the `id` parameter.
 * 
 * @param ptr A pointer to an `Atom`.
 * @param id The new ID.
*/
void atom_set_id(Atom *ptr, int id);

/**
 * Populates an array with a copy of the `position` parameter.
 * 
 * @param ptr A pointer to an `Atom`.
 * @param out The array into which `position` is copied.
*/
void atom_get_position(Atom *ptr, double out[3]);

/**
 * Sets a new value for the `position` parameter.
 * 
 * @param ptr A pointer to an `Atom`.
 * @param position The new position.
*/
void atom_set_position(Atom *ptr, double position[3]);

/**
 * A collection of `Atom`s in a bounding box.
 * 
 * @param basis The collection's coordinate system.
 * @param length The number of `Atom` pointers in the collection.
 * @param capacity The total number of allocated spaces for `Atom` pointers in the collection.
 * @param size The total number of allocated bytes.
 * @param atoms A dynamically sized array of pointers to `Atom`s in the collection.
*/
typedef struct
{
    double basis[3][3];
    size_t length;
    size_t capacity;
    size_t size;
    Atom *atoms[];
} AtomCollection;

/**
 * Returns a pointer to an initialized `AtomCollection`.
 * 
 * @param basis The collection's coordinate system.
 * @param length The number of `Atom` pointers in the collection.
 * @param capacity The total number of allocated spaces for `Atom` pointers in the collection.
 * @param atoms A dynamically sized array of pointers to `Atom`s in the collection.
*/
AtomCollection *atom_collection_new(double basis[3][3], size_t length, size_t capacity, Atom *atoms[]);

/**
 * Frees the memory associated with an `AtomCollection`.
 * 
 * @param ptr A pointer to an `AtomCollection`.
*/
void atom_collection_free(AtomCollection *ptr);

/**
 * Populates an array with a copy of the `basis` parameter
 * 
 * @param ptr A pointer to an `AtomCollection`.
 * @param out The output array into which `basis` is copied.
*/
void atom_collection_get_basis(AtomCollection *ptr, double out[3][3]);

/**
 * Sets a new value for the `basis` parameter.
 * 
 * @param ptr A pointer to an `AtomCollection` object.
 * @param basis The new basis.
*/
void atom_collection_set_basis(AtomCollection *ptr, double basis[3][3]);

/**
 * Populates an array with a copy of the `atoms` parameter.
 * 
 * @param ptr A pointer to an `AtomCollection`.
 * @param out The output array into which `atoms` is copied. 
*/
void atom_collection_get_atoms(AtomCollection *ptr, Atom *out[]);

/**
 * Sets a new value for the `atoms` parameter.
 * 
 * @param ptr A pointer to an `AtomCollection`.
 * @param length The length of parameter `atoms`.
 * @param capacity The capacity of parameter `atoms`.
 * @param atoms A dynamically sized array of `Atom` pointers.
*/
void atom_collection_set_atoms(AtomCollection *ptr, size_t length, size_t capacity, Atom *atoms[]);