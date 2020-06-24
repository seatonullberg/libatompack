/**
 * @file
 * @brief This file contains functions which operate on bounded point clouds.
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
*/
size_t nearest_neighbor(double position[3], double positions[][3], size_t length, double cell[3][3], int periodicity[3], double tolerance);

/**
 * Populates an array with the periodic transformation of a position in a cell.
 * 
 * @param position The initial position.
 * @param cell The bounding box represented as a 3x3 matrix.
 * @param periodicity An array indicating which directions are treated periodically.
 *      1 indicates periodic and 0 indicates nonperiodic.
 * @param tolerance The radius of tolerance.
 * @param out The array into which the transformed position is written.
*/
void periodic_image(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3]);

/**
 * Populates an array with the reduced periodic transformation of a position in a cell.
 * 
 * @param position The initial position.
 * @param cell The bounding box represented as a 3x3 matrix.
 * @param periodicity An array indicating which directions are treated periodically.
 *      1 indicates periodic and 0 indicates nonperiodic.
 * @param tolerance The radius of tolerance.
 * @param out The array into which the transformed position is written.
*/
void reduced_periodic_image(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3]);