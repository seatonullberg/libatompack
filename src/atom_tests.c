#include "atom.h"
#include "utest.h"

UTEST(AtomTests, test_atom_new)
{
    int id = 1;
    double position[3] = {1.0, 2.0, 3.0};
    Atom *atom = atom_new(id, position);

    int res_id = atom_get_id(atom);
    double res_position[3];
    atom_get_position(atom, res_position);

    EXPECT_EQ(res_id, 1);
    EXPECT_EQ(res_position[0], 1.0);
    EXPECT_EQ(res_position[1], 2.0);
    EXPECT_EQ(res_position[2], 3.0);

    atom_free(atom);
}

UTEST(AtomTests, test_atom_collection_new)
{
    int id = 1;
    double position[3] = {1.0, 2.0, 3.0};
    Atom *atom = atom_new(id, position);
    Atom *atoms[] = {atom};
    double basis[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    size_t length = 1;
    size_t capacity = 1;
    AtomCollection *ptr = atom_collection_new(basis, length, capacity, atoms);

    double res_basis[3][3];
    atom_collection_get_basis(ptr, res_basis);
    Atom *res_atoms[ptr->length];
    atom_collection_get_atoms(ptr, res_atoms);
    int res_id = res_atoms[0]->id;
    double res_position[3];
    for (int i = 0; i < 3; i++)
    {
        res_position[i] = res_atoms[0]->position[i];
    }

    EXPECT_EQ(res_basis[0][0], 1.0);
    EXPECT_EQ(res_basis[1][1], 1.0);
    EXPECT_EQ(res_basis[2][2], 1.0);
    EXPECT_EQ(res_id, 1);
    EXPECT_EQ(res_position[0], 1.0);
    EXPECT_EQ(res_position[1], 2.0);
    EXPECT_EQ(res_position[2], 3.0);

    atom_collection_free(ptr);
}