#include <math.h>
#include "util.h"

// Populates an array with the sum of two vectors.
void add(double a[3], double b[3], double out[3])
{
    for (int i = 0; i < 3; i++)
    {
        out[i] = a[i] + b[i];
    }
}

// Returns the angle between two vectors in radians.
double angle(double a[3], double b[3])
{
    double numerator = dot(a, b);
    double denominator = norm(a) * norm(b);
    return numerator / denominator;
}

// Populates an array with a copy of the cross product between two vectors.
double cross(double a[3], double b[3], double out[3])
{
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];
}

// Populates an array with the quotient of a vector and a scalar.
void div_scalar(double a[3], double b, double out[3])
{
    for (int i = 0; i < 3; i++)
    {
        out[i] = a[i] / b;
    }
}

// Returns the dot product of two vectors.
double dot(double a[3], double b[3])
{
    double prod = 0.0;
    for (int i = 0; i < 3; i++)
    {
        prod += a[i] * b[i];
    }
    return prod;
}

// Returns the euclidean distance between two vectors.
double euclidean(double a[3], double b[3])
{
    double sum = 0.0;
    for (int i = 0; i < 3; i++)
    {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

// Returns the l2 norm of a vector.
double norm(double a[3])
{
    double sum = 0.0;
    for (int i = 0; i < 3; i++)
    {
        sum += a[i] * a[i];
    }
    return sqrt(sum);
}

// Populates an array with the difference between two vectors.
void sub(double a[3], double b[3], double out[3])
{
    for (int i = 0; i < 3; i++)
    {
        out[i] = a[i] - b[i];
    }
}