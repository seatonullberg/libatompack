#include <math.h>
#include <stdlib.h>
#include "qr.h"
#include "utest.h"

int matrix_eq(double a[][3], double b[][3], size_t length, double tolerance)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (abs(a[i][j] - b[i][j]) > tolerance)
            {
                return 0; // false
            }
        }
    }
    return 1; // true
}

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
    ASSERT_TRUE(matrix_eq(q, target_q, 3, 1.0e-6));
    ASSERT_TRUE(matrix_eq(r, target_r, 3, 1.0e-6));
}