#include <math.h>
#include "cell.h"
#include "rmsd.h"
#include "nearest.h"
#include "qr.h"
#include "util.h"

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
    int out_ids[])
{
    // generate lattice vectors
    double lattice_vectors[3][3];

    metric_tensor(a, b, c, alpha, beta, gamma, lattice_vectors);

    // calculate magnitude of the lattice vectors and orientation
    double lattice_vectors_magnitude[3];
    double orientation_magnitude[3];

    for (int i = 0; i < 3; i++)
    {
        lattice_vectors_magnitude[i] = norm(lattice_vectors[i]);
        orientation_magnitude[i] = norm(orientation[i]);
    }

    // normalize lattice vectors and orientation to unit vectors
    double lattice_vectors_hat[3][3];
    double orientation_hat[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            lattice_vectors_hat[i][j] = lattice_vectors[i][j] / lattice_vectors_magnitude[i];
            orientation_hat[i][j] = orientation[i][j] / orientation_magnitude[i];
        }
    }

    // generate rotation matrix between lattice vectors and orientation
    double move_com[3], move_to_ref[3];
    double U[3][3];
    double rmsd;

    calculate_rotation_rmsd(lattice_vectors_hat, orientation_hat, 3, move_com, move_to_ref, U, &rmsd);

    // align the lattice vectors with the orientation
    double lattice_vectors_oriented[3][3];

    matmul(orientation, lattice_vectors, 3, lattice_vectors_oriented);

    // determine an orthogonal representation of the oriented lattice_vectors
    double qr_q[3][3], qr_r[3][3];
    double lattice_vectors_oriented_transposed[3][3];

    transpose(lattice_vectors_oriented, 3, lattice_vectors_oriented_transposed);
    qr(lattice_vectors_oriented_transposed, qr_q, qr_r);

    // calculate the magnitude of the oriented lattice vectors
    double lattice_vectors_oriented_magnitude[3];

    for (int i = 0; i < 3; i++)
    {
        lattice_vectors_oriented_magnitude[i] = norm(lattice_vectors_oriented[i]);
    }

    // determine the smallest number of duplications of the original
    // lattice required to encompass the orthogonal representation
    // of the oriented lattice.
    int min_repr[3];

    for (int i = 0; i < 3; i++)
    {
        min_repr[i] = round(ceil(lattice_vectors_oriented_magnitude[i] / lattice_vectors_magnitude[i]) * duplicates[i]);
    }

    // iterate through the lattice and determine valid positions
    int size_arr[3];

    for (int xsize = 0; xsize < min_repr[0]; xsize++)
    {
        for (int ysize = 0; ysize < min_repr[1]; ysize++)
        {
            for (int zsize = 0; zsize < min_repr[2]; zsize++)
            {
                size_arr[0] = xsize;
                size_arr[1] = ysize;
                size_arr[2] = zsize;

                // TODO: matrix multiplication between a 1x3 and a 3x3 to get offset
            }
        }
    }
}