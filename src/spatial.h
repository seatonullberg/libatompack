/**
 * @file
 * @brief This file contains functions which operate on bounded point clouds.
*/

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
void enforce_periodicity(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3]);