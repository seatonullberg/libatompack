#include "nearest.h"
#include "utest.h"
#include "util.h"

UTEST(NearestTests, test_nearest_neighbor_periodic)
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

UTEST(NearestTests, test_nearest_neighbor_nonperiodic)
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
    int periodicity[3] = {0, 0, 0};
    double tolerance = 1.0e-6;
    double out = 0.0;

    int res = nearest_neighbor(position, positions, length, cell, periodicity, tolerance, &out);
    EXPECT_EQ(res, 0);
    ASSERT_TRUE(out - 0.346410162 < tolerance);
}