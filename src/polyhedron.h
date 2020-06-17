/**
 * @file
 * @brief This file contains functions that work on a 3x3 matrix representation of a polyhedron.
*/

/**
 * Returns the vertices of a given polyhedron.
 * 
 * @param poly The 3X3 matrix representing a polyhedron.
 * @param out The array into which the vertices are written.
*/
void polyhedron_vertices(double poly[3][3], double out[8][3]);

/**
 * Returns the faces of a given polyhedron with an array of 3 points representing each face.
 * 
 * @param poly The 3x3 matrix representing a polyhedron.
 * @param out The array into which the faces are written.
*/
void polyhedron_faces(double poly[3][3], double out[6][3][3]);