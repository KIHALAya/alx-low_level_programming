/* Realized by : KIHAL Aya */
#include <stdio.h>
#include "main.h"
/**
 * print_triangle - print a triangle at a give size.
 * @size : size of triangle to print.
 *
 *return - nothing
 */
void print_triangle(int size)
{
	int i, m, d, to_print;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	d = size - 1;
	for (i = 0 ; i < size ; i++)
	{
		m = 0;
		while (m < (d - i))
		{
			_putchar(32);
			m++;
		}

		to_print = size - m;

		while (to_print > 0)
		{
			_putchar('#');
			to_print--;
		}
		_putchar('\n');
	}
}


