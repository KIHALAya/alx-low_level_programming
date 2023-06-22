/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * print_number - prints an integer
 * @n: input integer
 *
 * return - nothing
 **/
void print_number(int n)
{
	unsigned int i = n;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}

	if ((i / 10) > 0)
		print_number(i / 10);

	_putchar(i % 10 + '0');
}
