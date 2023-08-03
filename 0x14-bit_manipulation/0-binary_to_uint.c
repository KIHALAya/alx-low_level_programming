/* Author : KIHAL Aya */
#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string containing the binary number (0 and 1 chars).
 * Return: The converted number,
 *  or 0 if there's an invalid character or if b is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal_num = 0;
	int len = 0;
	int i;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
		len++;

	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] != '1' && b[i] != '0')
			return (0);
		else if (b[i] == '1')
		{
			decimal_num += (1 << (len - 1 - i));
		}
	}

	return (decimal_num);
}

