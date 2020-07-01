#include <stdlib.h>

int array_eq(double a[3], double b[3], double tolerance);
int matrix_eq(double a[][3], double b[][3], size_t length, double tolerance);

void add(double a[3], double b[3], double out[3]);
double angle(double a[3], double b[3]);
double cross(double a[3], double b[3], double out[3]);
void div_scalar(double a[3], double b, double out[3]);
double dot(double a[3], double b[3]);
double euclidean(double a[3], double b[3]);
void matmul(double a[][3], double b[][3], size_t length, double out[][3]);
double norm(double a[3]);
void sub(double a[3], double b[3], double out[3]);
void transpose(double a[][3], size_t length, double out[][3]);