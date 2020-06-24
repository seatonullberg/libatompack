#include "cell.h"
#include "utest.h"

UTEST(CellTests, test_is_point_in_cell_inside)
{
    double point[3] = {0.5, 0.5, 0.5};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    double tolerance = 1.0e-6;
    ASSERT_TRUE(is_point_in_cell(point, cell, tolerance));
}

UTEST(CellTests, test_is_point_in_cell_surface)
{
    double point[3] = {0.5, 0.5, 1.0};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    double tolerance = 1.0e-6;
    ASSERT_TRUE(is_point_in_cell(point, cell, tolerance));
}

UTEST(CellTests, test_is_point_in_cell_outside)
{
    double point[3] = {1.5, 1.5, 1.5};
    double cell[3][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
    };
    double tolerance = 1.0e-6;
    ASSERT_FALSE(is_point_in_cell(point, cell, tolerance));
}