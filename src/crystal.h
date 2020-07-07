#include <stdlib.h>

size_t build_crystal(
    double a,
    double b,
    double c,
    double alpha,
    double beta,
    double gamma,
    double lattice_sites[][3],
    int lattice_ids[],
    size_t length,
    double orientation[3][3],
    double duplicates[3],
    double tolerance,
    double out_basis[3][3],
    double out_positions[][3],
    int out_ids[]);