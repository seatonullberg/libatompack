#include <math.h>
#include <stdlib.h>

double dist(double a[], double b[], size_t N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

double dot(double a[], double b[], size_t N) {
    double prod = 0.0;
    for (int i = 0; i < N; i++) {
        prod += a[i] * b[i];
    }
    return prod;
}

double norm(double a[], size_t N) {
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += a[i] * a[i];
    }
    return sqrt(sum);
}