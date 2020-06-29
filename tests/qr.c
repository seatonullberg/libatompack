#include <math.h>
#include "qr.h"
#include "utest.h"
#include "util.h"

UTEST(QRTests, test_qr)
{
    double a[3][3] = {
        {-1.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 1.0, 0.0},
    };
    double q[3][3], r[3][3];
    double target_q[3][3] = {
        {sqrt(2.0) / 2, -sqrt(2.0) / 2, 0.0},
        {0.0, 0.0, 1.0},
        {-sqrt(2.0) / 2, -sqrt(2.0) / 2, 0.0},
    };
    double target_r[3][3] = {
        {-sqrt(2.0), 0.0, 0.0},
        {0.0, -sqrt(2.0), 0.0},
        {0.0, 0.0, 1.0},
    };

    qr(a, q, r);
    EXPECT_TRUE(matrix_eq(q, target_q, 1.0e-6));
    EXPECT_TRUE(matrix_eq(r, target_r, 1.0e-6));
}