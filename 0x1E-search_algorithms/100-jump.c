#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 *
 * @array: is a pointer to the first element of the array to search in
 * @size:  is the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located,
 * return -1 If value is not present in array or if array is NULL
 */

int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size);
	size_t i, j;

	if (array == NULL || size == 0)
		return (-1);

	for (i = 0; i < size; i += jump)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] <= value && (i + jump >= size || array[i + jump] >= value))
		{
			printf("Value found between indexes [%ld] and [%ld]\n", i, i + jump);
			for (j = i; j <= i + jump && j < size; j++)
			{
				printf("Value checked array[%ld] = [%d]\n", j, array[j]);
				if (array[j] == value)
					return (j);
			}
			break;
		}
	}

	return (-1);
}

