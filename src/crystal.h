/**
 * @file
 * @brief This file contains routines to build arbitrary crystal structures.
*/

/**
 * Populates an array with the metric tensor for a given set of lattice parameters.
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