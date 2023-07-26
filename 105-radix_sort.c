#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers based on a specific digit
 * using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The exponent of the specific digit
 */
void counting_sort(int *array, size_t size, int exp)
{
size_t i;
int *output, count[10] = {0};

    output = malloc(size * sizeof(int));
    if (output == NULL)
        return;
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm (LSD approach)
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
size_t i;
int max;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}
