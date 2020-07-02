#include <math.h>
#include "util.h"

// Populates an array with the vertices of a cell.
void _cell_vertices(double cell[3][3], double out[8][3])
{
    double origin[3] = {0.0, 0.0, 0.0};
    double x[3] = {cell[0][0], cell[0][1], cell[0][2]};
    double y[3] = {cell[1][0], cell[1][1], cell[1][2]};
    double z[3] = {cell[2][0], cell[2][1], cell[2][2]};
    double xy[3] = {
        cell[0][0] + cell[1][0],
        cell[0][1] + cell[1][1],
        cell[0][2] + cell[1][2],
    };
    double xz[3] = {
        cell[0][0] + cell[2][0],
        cell[0][1] + cell[2][1],
        cell[0][2] + cell[2][2],
    };
    double yz[3] = {
        cell[1][0] + cell[2][0],
        cell[1][1] + cell[2][1],
        cell[1][2] + cell[2][2],
    };
    double xyz[3] = {
        cell[0][0] + cell[1][0] + cell[2][0],
        cell[0][1] + cell[1][1] + cell[2][1],
        cell[0][2] + cell[1][2] + cell[2][2],
    };
    for (int i = 0; i < 3; i++)
    {
        out[0][i] = origin[i];
        out[1][i] = x[i];
        out[2][i] = y[i];
        out[3][i] = z[i];
        out[4][i] = xy[i];
        out[5][i] = xz[i];
        out[6][i] = yz[i];
        out[7][i] = xyz[i];
    }
}

// Populates an array with the faces of a cell represented as an array of 3 coplanar points.
void _cell_faces(double cell[3][3], double out[6][3][3])
{
    double verts[8][3];
    _cell_vertices(cell, verts);
    for (int i = 0; i < 3; i++)
    {
        // lower xy
        out[0][0][i] = verts[4][i];
        out[0][1][i] = verts[1][i];
        out[0][2][i] = verts[2][i];
        // upper xy
        out[1][0][i] = verts[7][i];
        out[1][1][i] = verts[6][i];
        out[1][2][i] = verts[5][i];
        // rear xz
        out[2][0][i] = verts[5][i];
        out[2][1][i] = verts[3][i];
        out[2][2][i] = verts[1][i];
        // front xz
        out[3][0][i] = verts[2][i];
        out[3][1][i] = verts[6][i];
        out[3][2][i] = verts[4][i];
        // left yz
        out[4][0][i] = verts[6][i];
        out[4][1][i] = verts[2][i];
        out[4][2][i] = verts[3][i];
        // right yz
        out[5][0][i] = verts[1][i];
        out[5][1][i] = verts[4][i];
        out[5][2][i] = verts[5][i];
    }
}

// Populates an array with the vector normal to each face on the cell.
void _cell_normals(double cell[3][3], double out[6][3])
{
    double d;
    double a[3], b[3], n[3];
    double faces[6][3][3];
    _cell_faces(cell, faces);
    for (int i = 0; i < 6; i++)
    {
        sub(faces[i][1], faces[i][0], a);
        sub(faces[i][2], faces[i][0], b);
        cross(a, b, n);
        d = norm(n);
        div_scalar(n, d, out[i]);
    }
}

int cell_contains(double cell[3][3], double position[3], double tolerance)
{
    double faces[6][3][3];
    _cell_faces(cell, faces);
    double normals[6][3];
    _cell_normals(cell, normals);
    double p2f[3], reduced_normal[3];
    double d, p2f_norm;

    for (int i = 0; i < 6; i++)
    {
        sub(faces[i][0], position, p2f);
        p2f_norm = norm(p2f);
        div_scalar(normals[i], p2f_norm, reduced_normal);
        d = dot(p2f, reduced_normal);
        if (d < -tolerance)
        {
            return 0; // false
        }
    }
    return 1; // true
}

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