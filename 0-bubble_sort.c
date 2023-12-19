#include "sort.h"

/**
 * bubble_sort - This simply sorts an array of integers
 * in ascending order
 * @array: array to hold ints
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
    int swapped, m, n;

    for (m = 0; m < (int)size - 1; m++)
    {
        swapped = 0;

        for (n = 0; n < (int)size - m - 1; n++)
        {
            if (array[n] > array[n + 1])
            {
                int temp = array[n];

                array[n] = array[n + 1];
                array[n + 1] = temp;
                swapped = 1;
                /* Print the current state of the array after each pass */
                print_array(array, size);
            }
        }
        /* If no two elements were swapped by inner loop, then break */
        if (swapped == 0)
            break;
    }
}
