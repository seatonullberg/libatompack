#include <math.h>
#include "rmsd.h"
#include "utest.h"
#include "util.h"

UTEST(RMSDTests, test_calculate_rotation_rmsd)
{
    double ref_xlist[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    double mov_xlist[3][3] = {
        {-1.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 1.0, 0.0},
    };
    double move_com[3], move_to_ref[3];
    double U[3][3];
    double rmsd = 0.0;
    double target_U[3][3] = {
        {-0.707107, 0.696923, 0.119573},
        {0.0, -0.169102, 0.985599},
        {0.707107, 0.696923, 0.119573},
    };

    calculate_rotation_rmsd(ref_xlist, mov_xlist, 3, move_com, move_to_ref, U, &rmsd);
    ASSERT_TRUE(matrix_eq(U, target_U, 1.0e-6));
}