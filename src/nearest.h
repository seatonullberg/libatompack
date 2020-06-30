/**
 * @file
 * @brief This file contains an implementation of nearest neighbors search in periodic space.
*/

#include <stdlib.h>

/**
 * Returns the index of the nearest neighbor to a given position in an array of positions.
 * 
 * @param position The initial position.
 * @param positions The array of positions.
 * @param length The length of the `positions` parameter.
 * @param cell The bounding box represented as a 3x3 matrix.
 * @param periodicity An array indicating which directions are treated periodically.
 *      1 indicates periodic and 0 indicates nonperiodic.
 * @param tolerance The radius of tolerance.
 * @param out The distance to the nearest neighbor
*/
size_t nearest_neighbor(double position[3], double positions[][3], size_t length, double cell[3][3], int periodicity[3], double tolerance, double *out);

void periodic_image(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3]);
void reduced_periodic_image(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3]);