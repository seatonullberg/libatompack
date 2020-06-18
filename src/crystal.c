#include <math.h>

void metric_tensor(double a, double b, double c, double alpha, double beta, double gamma, double out[3][3])
{
    out[0][0] = a * a;
    out[0][1] = a * b * cos(gamma);
    out[0][2] = a * c * cos(beta);
    out[1][0] = a * b * cos(gamma);
    out[1][1] = b * b;
    out[1][2] = b * c * cos(alpha);
    out[2][0] = a * c * cos(beta);
    out[2][1] = b * c * cos(alpha);
    out[2][2] = c * c;
}