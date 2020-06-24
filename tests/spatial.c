#include "spatial.h"
#include "utest.h"

UTEST(SpatialTests, test_enforce_periodicity)
{
    double position[3] = {1.50, 1.50, 0.50};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    int periodicity[3] = {1, 0, 1};
    double tolerance = 1.0e-6;
    double out[3];

    enforce_periodicity(position, cell, periodicity, tolerance, out);
    EXPECT_EQ(out[0], 0.50);
    EXPECT_EQ(out[1], 1.50);
    EXPECT_EQ(out[2], 0.50);
}