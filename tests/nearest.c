#include "nearest.h"
#include "utest.h"
#include "util.h"

UTEST(NearestTests, test_nearest_neighbor)
{
    double position[3] = {0.0, 0.0, 0.0};
    double positions[][3] = {
        {0.2, 0.2, 0.2},
        {0.5, 0.5, 0.5},
        {0.9, 0.9, 0.9},
    };
    size_t length = 3;
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    int periodicity[3] = {1, 1, 1};
    double tolerance = 1.0e-6;
    double out = 0.0;

    int res = nearest_neighbor(position, positions, length, cell, periodicity, tolerance, &out);
    EXPECT_EQ(res, 2);
    ASSERT_TRUE(out - 0.173205081 < tolerance);
}

UTEST(NearestTests, test_periodic_image)
{
    double position[3] = {1.75, 1.75, 0.25};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    int periodicity[3] = {1, 0, 1};
    double tolerance = 1.0e-6;
    double out[3];
    double target[3] = {0.75, 1.75, 0.25};
    periodic_image(position, cell, periodicity, tolerance, out);
    ASSERT_TRUE(array_eq(out, target, 1.0e-15))
}

UTEST(NearestTests, test_reduced_periodic_image)
{
    double position[3] = {1.75, 1.75, 0.25};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    int periodicity[3] = {1, 0, 1};
    double tolerance = 1.0e-6;
    double out[3];
    double target[3] = {0.25, 1.75, 0.25};
    reduced_periodic_image(position, cell, periodicity, tolerance, out);
    ASSERT_TRUE(array_eq(out, target, 1.0e-15));
}