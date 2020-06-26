/**
 * @file
 * @brief This file contains functions which operate on 3x3 matrix representation of a parallelepiped cell.
*/

/**
 * Returns 1 if the position is within the cell else 0.
 * 
 * @param cell 3x3 matrix representation of a cell.
 * @param position 3D position vector.
 * @param tolerance Radius of tolerance.
*/
int cell_contains(double cell[3][3], double position[3], double tolerance);

/**
 * Populates a 3x3 matrix with the metric tensor for a given set of lattice parameters.
 * 
 * @param a The \\(a\\) distance parameter.
 * @param b The \\(b\\) distance parameter.
 * @param c The \\(c\\) distance parameter.
 * @param alpha The \\(\alpha\\) angle parameter (in radians).
 * @param beta The \\(\beta\\) angle parameter (in radians).
 * @param gamma The \\(\gamma\\) angle parameter (in radians).
 * @param out The output array into which the metric tensor is copied.
*/
void metric_tensor(double a, double b, double c, double alpha, double beta, double gamma, double out[3][3]);