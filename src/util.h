#include <stdlib.h>

#define PI 3.14159265358979323846

double dist(double a[], double b[], size_t N);
double dot(double a[], double b[], size_t N);
double norm(double a[], size_t N);
void metric_tensor(double a, double b, double c, double alpha, double beta, double gamma, double out[3][3]);
void polyhedron_vertices(double poly[3][3], double out[8][3]);