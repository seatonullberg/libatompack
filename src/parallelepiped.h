/**
 * @file
 * @brief This file contains functions which operate on 3x3 matrix representations of parallelepipeds.
*/

/**
 * Returns the vertices of a given parallelepiped.
 * 
 * @param para A 3X3 matrix representation of the parallelepiped.
 * @param out The array into which the vertices are copied.
*/
void parallelepiped_vertices(double para[3][3], double out[8][3]);

/**
 * Returns the faces of a given parallelepiped with an array of 3 points representing each face.
 * 
 * @param para A 3x3 matrix representation of the parallelepiped.
 * @param out The array into which the faces are copied.
*/
void parallelepiped_faces(double para[3][3], double out[6][3][3]);