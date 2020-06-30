#include <float.h>
#include <stdlib.h>
#include "util.h"

void periodic_image(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3])
{
    double cell_norm, res;

    for (int i = 0; i < 3; i++)
    {
        cell_norm = norm(cell[i]);
        res = position[i];
        if (periodicity[i])
        {
            if (res < -tolerance)
            {
                while (res < -tolerance)
                {
                    res += cell_norm;
                }
            }
            else if (res > cell_norm - tolerance)
            {
                while (res > cell_norm - tolerance)
                {
                    res -= cell_norm;
                }
            }
        }
        out[i] = res;
    }
}

void reduced_periodic_image(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3])
{
    double cell_norm, res;

    periodic_image(position, cell, periodicity, tolerance, out);
    for (int i = 0; i < 3; i++)
    {
        if (periodicity[i])
        {
            cell_norm = norm(cell[i]);
            if (out[i] > cell_norm / 2.0)
            {
                out[i] = cell_norm - out[i];
            }
        }
    }
}

size_t nearest_neighbor(double position[3], double positions[][3], size_t length, double cell[3][3], int periodicity[3], double tolerance, double *out)
{
    size_t index;
    double tmp_distance;
    double reduced_position_a[3], reduced_position_b[3];
    double distance = DBL_MAX;

    for (int i = 0; i < length; i++)
    {
        reduced_periodic_image(position, cell, periodicity, tolerance, reduced_position_a);
        reduced_periodic_image(positions[i], cell, periodicity, tolerance, reduced_position_b);
        tmp_distance = euclidean(reduced_position_a, reduced_position_b);
        if (tmp_distance < distance)
        {
            index = i;
            distance = tmp_distance;
        }
    }
    *out = distance;
    return index;
}