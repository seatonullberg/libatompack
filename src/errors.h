/**
 * @file
 * @brief This file defines the possible error codes.
*/

#include <stdio.h>

/**
 * Enumeration of all error codes.
*/
typedef enum
{
    OK = 0,
    POSITION_OCCUPIED = 1,
    POSITION_UNOCCUPIED = 2,
    POSITION_EXTERNAL = 3,
    CRYSTALLOGRAPHY_INVALID = 4,
} ERROR_CODE;

/**
 * Prints information about a given `ERROR_CODE`.
 * 
 * @param err The `ERROR_CODE` to process.
*/
void display_error(ERROR_CODE err)
{
    switch (err)
    {
    case OK:
        printf("OK: No error occured.\n");
    case POSITION_OCCUPIED:
        printf("POSITION_OCCUPIED: An atom exists within the radius of tolerance.\n");
    case POSITION_UNOCCUPIED:
        printf("POSITION_UNOCCUPIED: No atoms exist within the radius of tolerance.\n");
    case POSITION_EXTERNAL:
        printf("POSITION_EXTERNAL: The position is outside of the bounding box.\n");
    case CRYSTALLOGRAPHY_INVALID:
        printf("CRYSTALLOGRAPHY_INVALID: Crystallographic constraints are not satisfied.\n");
    default:
        printf("???: Unknown error code.\n");
    }
}