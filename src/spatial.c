#include <stdlib.h>
#include "util.h"

void enforce_periodicity(double position[3], double cell[3][3], int periodicity[3], double tolerance, double out[3])
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
