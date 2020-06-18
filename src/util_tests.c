#include <math.h>
#include "utest.h"
#include "util.h"

UTEST(UtilTests, test_angle)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};

    ASSERT_EQ(angle(a, b, 3), 0.7142857142857143);
}

UTEST(UtilTests, test_dot)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};

    ASSERT_EQ(dot(a, b, 3), 10);
}

UTEST(UtilTests, test_euclidean)
{
    double a[3] = {1.0, 2.0, 3.0};
    double b[3] = {3.0, 2.0, 1.0};

    ASSERT_EQ(euclidean(a, b, 3), sqrt(8.0));
}

UTEST(UtilTests, test_norm)
{
    double a[3] = {1.0, 2.0, 3.0};

    ASSERT_EQ(norm(a, 3), sqrt(14.0));
}