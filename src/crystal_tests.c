#include "constants.h"
#include "crystal.h"
#include "utest.h"

UTEST(CrystalTests, test_metric_tensor)
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