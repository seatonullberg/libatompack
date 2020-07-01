#include <math.h>
#include "utest.h"
#include "util.h"

UTEST(UtilTests, test_add)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};
    double out[3];
    double target[3] = {4.0, 4.0, 4.0};
    add(a, b, out);
    ASSERT_TRUE(array_eq(out, target, 1.0e-15));
}

UTEST(UtilTests, test_angle)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};
    ASSERT_EQ(angle(a, b), 0.7142857142857143);
}

UTEST(UtilTests, test_cross)
{
    double a[3] = {2.0, 3.0, 4.0};
    double b[3] = {5.0, 6.0, 7.0};
    double out[3];
    double target[3] = {-3.0, 6.0, -3.0};
    cross(a, b, out);
    ASSERT_TRUE(array_eq(out, target, 1.0e-15));
}

UTEST(UtilTests, test_div_scalar)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b = 2.0;
    double out[3];
    double target[3] = {0.5, 1.0, 1.5};
    div_scalar(a, b, out);
    ASSERT_TRUE(array_eq(out, target, 1.0e-15));
}

UTEST(UtilTests, test_dot)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};
    ASSERT_EQ(dot(a, b), 10);
}

UTEST(UtilTests, test_euclidean)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};
    ASSERT_EQ(euclidean(a, b), sqrt(8.0));
}

UTEST(UtilTests, test_matmul)
{
    double a[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
    };
    double b[3][3] = {
        {2.0, 4.0, 6.0},
        {8.0, 10.0, 12.0},
        {14.0, 16.0, 18.0},
    };
    double out[3][3];
    double target[3][3] = {
        {60.0, 72.0, 84.0},
        {132.0, 162.0, 192.0},
        {204.0, 252.0, 300.0},
    };
    matmul(a, b, 3, out);
    ASSERT_TRUE(matrix_eq(out, target, 3, 1.0e-15));
}

UTEST(UtilTests, test_norm)
{
    double a[3] = {1.0, 2.0, 3.0};
    ASSERT_EQ(norm(a), sqrt(14.0));
}

UTEST(UtilTests, test_sub)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};
    double out[3];
    double target[3] = {-2.0, 0.0, 2.0};
    sub(a, b, out);
    ASSERT_TRUE(array_eq(out, target, 1.0e-15));
}

UTEST(UtilTests, test_transpose)
{
    double a[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
    };
    double out[3][3];
    double target[3][3] = {
        {1.0, 4.0, 7.0},
        {2.0, 5.0, 8.0},
        {3.0, 6.0, 9.0},
    };
    transpose(a, 3, out);
    ASSERT_TRUE(matrix_eq(out, target, 3, 1.0e-15));
}