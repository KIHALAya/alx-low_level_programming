/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * print_to_98 - prints all natural numbers from n to 98.
 * @n: the number to start counting from to 98
 * Return: void returns nothing.
 */
void print_to_98(int n)
{
	if (n < 98)
	{
		for (n = n; n < 98; n++)
			_putchar(n);
		_putchar(98);
	}
	else
	{
		for (n = n; n > 98; n--)
			_putchar(n);
		_putchar(98);
	}
}
