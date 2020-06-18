void parallelepiped_vertices(double para[3][3], double out[8][3])
{
    double origin[3] = {0.0, 0.0, 0.0};
    double x[3] = {para[0][0], para[0][1], para[0][2]};
    double y[3] = {para[1][0], para[1][1], para[1][2]};
    double z[3] = {para[2][0], para[2][1], para[2][2]};
    double xy[3] = {
        para[0][0] + para[1][0],
        para[0][1] + para[1][1],
        para[0][2] + para[1][2],
    };
    double xz[3] = {
        para[0][0] + para[2][0],
        para[0][1] + para[2][1],
        para[0][2] + para[2][2],
    };
    double yz[3] = {
        para[1][0] + para[2][0],
        para[1][1] + para[2][1],
        para[1][2] + para[2][2],
    };
    double xyz[3] = {
        para[0][0] + para[1][0] + para[2][0],
        para[0][1] + para[1][1] + para[2][1],
        para[0][2] + para[1][2] + para[2][2],
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

void parallelepiped_faces(double para[3][3], double out[6][3][3])
{
    double verts[8][3];
    parallelepiped_vertices(para, verts);
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