#include <math.h>

double **metric_tensor(double a, double b, double c, double alpha, double beta, double gamma)
{
    double m[3][3] = {
        {a * a, a * b * cos(gamma), a * c * cos(beta)},
        {a * b * cos(gamma), b * b, b * c * cos(alpha)},
        {a * c * cos(beta), b * c * cos(alpha), c * c},
    };
    return &m;
}

double **polyhedron_vertices(double **poly)
{
    double m[8][3] = {
        {0.0, 0.0, 0.0}, // origin
        *poly[0],        // x corner
        *poly[1],        // y corner
        *poly[2],        // z corner
        {
            poly[0][0] + poly[1][0],
            poly[0][1] + poly[1][1],
            poly[0][2] + poly[1][2],
        }, // xy corner
        {
            poly[0][0] + poly[2][0],
            poly[0][1] + poly[2][1],
            poly[0][2] + poly[2][2],
        }, // xz corner
        {
            poly[1][0] + poly[2][0],
            poly[1][1] + poly[2][1],
            poly[1][2] + poly[2][2],
        }, // yz corner
        {
            poly[0][0] + poly[1][0] + poly[2][0],
            poly[0][1] + poly[1][1] + poly[2][1],
            poly[0][2] + poly[1][2] + poly[2][2],
        }, // xyz corner
    };
    return &m;
}

double **polyhedron_faces(double **poly)
{
    double **verts = polyhedron_vertices(poly);
    double m[6][3] = {
        {*verts[4], *verts[1], *verts[2]}, // lower xy
        {*verts[7], *verts[6], *verts[5]}, // upper xy
        {*verts[5], *verts[3], *verts[1]}, // rear xz
        {*verts[2], *verts[6], *verts[4]}, // front xz
        {*verts[6], *verts[2], *verts[3]}, // left yz
        {*verts[1], *verts[4], *verts[5]}, // right yz
    };
    return &m;
}
