/* Author : KIHAL Aya */
#include "main.h"

#include <stdio.h>

/**
 * print_binary - Prints the binary representation of an unsigned long integer.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	int pos = sizeof(n) * 8 - 1;
	int bit_pos;

	if (n == 0)
	{
		printf("0");
		return;
	}

	while (!((n >> pos) & 1))
		pos--;

	for (bit_pos = pos; bit_pos >= 0; bit_pos--)
	{
		if ((n >> bit_pos) & 1)
			printf("1");
		else
			printf("0");
	}
}

