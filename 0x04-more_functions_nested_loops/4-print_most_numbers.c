/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * print_most_numbers - prints the numbers, from 0 to 9
 * Do not print 2 and 4
 *
 * return - nothing
 */
void print_most_numbers(void)
{
	int n = 0;

	while (n < 10)
	{
		if (n != 2 && n != 4)
			_putchar('0' + n);
		n++;
	}
	_putchar('\n');
}

