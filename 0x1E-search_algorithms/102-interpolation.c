#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the interpolation search algorithm
 *
 * @array: is a pointer to the first element of the array to search in
 * @size:  is the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located,
 * return -1 If value is not present in array or if array is NULL
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t pos;
	size_t low = 0;
	size_t high = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos = low + (((double)(high - low) /
					(array[high] - array[low])) * (value - array[low]));

		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

		if (value == array[pos])
		{
			return (pos);
		} else if (value < array[pos])
		{
			high = pos - 1;
		} else
		{
			low = pos + 1;
		}
	}

	printf("Value checked array[%ld] is out of range\n", pos);
	return (-1);
}

