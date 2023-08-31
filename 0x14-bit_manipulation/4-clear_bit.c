/* Author : KIHAL Aya */
#include "main.h"

/**
 * clear_bit - Clears a bit at a given index
 * @n: Pointer to the unsigned long integer
 * @index: Index of the bit to be cleared
 * Return: 1 on success, -1 on error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1 << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n = *n & ~mask;

	return (1);
}

