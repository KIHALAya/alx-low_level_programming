/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * print_line -  draws a straight line in the terminal..
 * @n: length of the line.
 *
 *return - nothing
 */
void print_line(int n)
{
	while (!(n <= 0))
	{
		_putchar('_');
		n--;
}
	_putchar('\n');
}


