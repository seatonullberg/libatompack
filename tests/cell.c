#include "cell.h"
#include "constants.h"
#include "utest.h"

UTEST(CellTests, test_metric_tensor)
{
    double a, b, c, alpha, beta, gamma;
    a = 2.0;
    b = 2.0;
    c = 2.0;
    alpha = PI / 2.0;
    beta = PI / 2.0;
    gamma = PI / 2.0;
    double m[3][3];
    metric_tensor(a, b, c, alpha, beta, gamma, m);

    EXPECT_EQ(m[0][0], 4.0);
    EXPECT_EQ(m[1][1], 4.0);
    EXPECT_EQ(m[2][2], 4.0);
}

UTEST(CellTests, test_cell_contains_inside)
{
    double position[3] = {0.5, 0.5, 0.5};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    double tolerance = 1.0e-6;
    ASSERT_TRUE(cell_contains(cell, position, tolerance));
}

UTEST(CellTests, test_cell_contains_surface)
{
    double position[3] = {0.5, 0.5, 1.0};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    double tolerance = 1.0e-6;
    ASSERT_TRUE(cell_contains(cell, position, tolerance));
}

UTEST(CellTests, test_cell_contains_outside)
{
    double position[3] = {1.5, 1.5, 1.5};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    double tolerance = 1.0e-6;
    ASSERT_FALSE(cell_contains(cell, position, tolerance));
}