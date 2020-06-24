#include <math.h>
#include "utest.h"
#include "util.h"

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
    double prod[3];
    cross(a, b, prod);

    EXPECT_EQ(prod[0], -3.0);
    EXPECT_EQ(prod[1], 6.0);
    EXPECT_EQ(prod[2], -3.0);
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

UTEST(UtilTests, test_norm)
{
    double a[3] = {1.0, 2.0, 3.0};

    ASSERT_EQ(norm(a), sqrt(14.0));
}