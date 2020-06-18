#include <math.h>
#include <stdlib.h>
#include "util.h"

// Returns the angle between two vectors in radians.
double angle(double a[], double b[], size_t N)
{
    double numerator = dot(a, b, N);
    double denominator = norm(a, N) * norm(b, N);
    return numerator / denominator;
}

// Returns the dot product of two vectors.
double dot(double a[], double b[], size_t N)
{
    double prod = 0.0;
    for (int i = 0; i < N; i++)
    {
        prod += a[i] * b[i];
    }
    return prod;
}

// Returns the euclidean distance between two vectors.
double euclidean(double a[], double b[], size_t N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

// Returns the l2 norm of a vector.
double norm(double a[], size_t N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i] * a[i];
    }
    return sqrt(sum);
}