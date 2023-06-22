/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * print_diagonal -  draws a diagonal line on the terminal.
 * @n: length to print to.
 *
 * return - nothing
 */
void print_diagonal(int n)
{
	int p, i;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0 ; i < n ; i++)
	{
		p = i;
		while (p > 0)
		{
			_putchar(32);
			p--;
		}
		_putchar('\\');
		_putchar('\n');
	}
}


