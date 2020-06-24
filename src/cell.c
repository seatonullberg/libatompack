#include <stdio.h>
#include <math.h>
#include "util.h"

void cell_vertices(double cell[3][3], double out[8][3])
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

void cell_faces(double cell[3][3], double out[6][3][3])
{
    double verts[8][3];
    cell_vertices(cell, verts);
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

void cell_normals(double cell[3][3], double out[6][3])
{
    double d;
    double a[3], b[3], n[3];
    double faces[6][3][3];
    cell_faces(cell, faces);
    for (int i = 0; i < 6; i++)
    {
        sub(faces[i][1], faces[i][0], a);
        sub(faces[i][2], faces[i][0], b);
        cross(a, b, n);
        d = norm(n);
        div_scalar(n, d, out[i]);
    }
}

int is_point_in_cell(double point[3], double cell[3][3], double tolerance)
{
    double faces[6][3][3];
    cell_faces(cell, faces);
    double normals[6][3];
    cell_normals(cell, normals);
    double p2f[3], reduced_normal[3];
    double d, p2f_norm;

    for (int i = 0; i < 6; i++)
    {
        sub(faces[i][0], point, p2f);
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