#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of integers
 * using the Binary search algorithm
 *
 * @array: is a pointer to the first element of the array to search in
 * @size:  is the number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located,
 * return -1 If value is not present in array or if array is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	int low = 0;
	int high = size - 1;
	int mid;
	int index = -1;
	int i;


	if (array == NULL)
		return (-1);

	while (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in array: %d", array[low]);
		for (i = low + 1; i <= high; i++)
			printf(", %d", array[i]);
		printf("\n");

		if (array[mid] == value)
		{
			index = mid;
			break;
		}
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;

	}

	return (index);
}

