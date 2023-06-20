/* Realized by : KIHAL Aya */
#include "main.h"
/**
 * _islower - checks for lowercase character.
 * @c: character to test.
 * Return: 1 if it is a lowercase letter, 0 if it is not a lowercase letter.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
