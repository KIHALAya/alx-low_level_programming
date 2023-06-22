/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * print_numbers - prints 0 to 9.
 *
 * return - nothing
 */
void print_numbers(void)
{
	int n = 0;

	while (n < 10)
	{
		_putchar('0' + n);
		n++;
	}
	_putchar('\n');
}


