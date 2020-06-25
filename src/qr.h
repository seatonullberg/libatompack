/**
 * @file
 * @brief This file contains an implementation of the QR decomposition.
*/

/**
 * Populates the array `out_q` with the orthogonal matrix and the array `out_r` with the upper triangular matrix.
 * 
 * @param a The input matrix.
 * @param out_q The array into which the orthogonal matrix Q is written.
 * @param out_r The array into which the upper triangular matrix R is written.
*/
void qr(double a[3][3], double out_q[3][3], double out_r[3][3]);