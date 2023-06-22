/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * more_numbers - prints 10 times the numbers, from 0 to 14.
 *
 * return - nothing
 */
void more_numbers(void)
{
	int i;
	int num = 0;

	for (i = 0 ; i < 10 ; i++)
	{
		while (num < 15)
		{
			if (num > 9)
				_putchar('0' + num / 10);
			_putchar('0' + num % 10);
			num++;
		}
		num = 0;
		_putchar('\n');
	}
}


