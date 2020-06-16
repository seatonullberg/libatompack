#include <math.h>
#include <string.h>

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

void polyhedron_vertices(double poly[3][3], double out[8][3])
{
    double origin[3] = {0.0, 0.0, 0.0};
    double x[3] = {poly[0][0], poly[0][1], poly[0][2]};
    double y[3] = {poly[1][0], poly[1][1], poly[1][2]};
    double z[3] = {poly[2][0], poly[2][1], poly[2][2]};
    double xy[3] = {
        poly[0][0] + poly[1][0],
        poly[0][1] + poly[1][1],
        poly[0][2] + poly[1][2],
    };
    double xz[3] = {
        poly[0][0] + poly[2][0],
        poly[0][1] + poly[2][1],
        poly[0][2] + poly[2][2],
    };
    double yz[3] = {
        poly[1][0] + poly[2][0],
        poly[1][1] + poly[2][1],
        poly[1][2] + poly[2][2],
    };
    double xyz[3] = {
        poly[0][0] + poly[1][0] + poly[2][0],
        poly[0][1] + poly[1][1] + poly[2][1],
        poly[0][2] + poly[1][2] + poly[2][2],
    };
    size_t row_size = sizeof(double) * 3;
    memcpy(out[0], &origin, row_size);
    memcpy(out[1], &x, row_size);
    memcpy(out[2], &y, row_size);
    memcpy(out[3], &z, row_size);
    memcpy(out[4], &xy, row_size);
    memcpy(out[5], &xz, row_size);
    memcpy(out[6], &yz, row_size);
    memcpy(out[7], &xyz, row_size);
}
