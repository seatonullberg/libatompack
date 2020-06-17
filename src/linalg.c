#include <math.h>
#include <stdlib.h>
#include "linalg.h"

double angle(double a[], double b[], size_t N)
{
    double numerator = dot(a, b, N);
    double denominator = norm(a, N) * norm(b, N);
    return numerator / denominator;
}

double dot(double a[], double b[], size_t N)
{
    double prod = 0.0;
    for (int i = 0; i < N; i++)
    {
        prod += a[i] * b[i];
    }
    return prod;
}

double euclidean(double a[], double b[], size_t N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

double norm(double a[], size_t N)
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i] * a[i];
    }
    return sqrt(sum);
}