/**
 * @file
 * @brief This file contains functions which operate on 3x3 matrix representations of parallelepiped cells.
*/

/**
 * Populates an array with the vertices of a given cell.
 * 
 * @param cell A 3X3 matrix representation of the cell.
 * @param out The array into which the vertices are copied.
*/
void cell_vertices(double cell[3][3], double out[8][3]);

/**
 * Populates an array with the faces of a given cell with an array of 3 points representing each face.
 * 
 * @param cell A 3x3 matrix representation of the cell.
 * @param out The array into which the faces are copied.
*/
void cell_faces(double cell[3][3], double out[6][3][3]);

/**
 * Populates an array with the normal vectors of a given cell.
 * 
 * @param cell A 3x3 matrix representation of a given cell.
 * @param out The array into which the normal vectors are copied.
*/
void cell_normals(double cell[3][3], double out[6][3]);

/**
 * Returns 1 if the point is within the cell else 0.
 * 
 * @param point The point to test.
 * @param cell The cell to consider.
 * @param tolerance The radius of tolerance.
*/
int is_point_in_cell(double point[3], double cell[3][3], double tolerance);