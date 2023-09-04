/* Author : KIHAL Aya */
#include "main.h"
/**
 * lenofstr - return the length of string.
 * @string: string we desire determin the length of.
 *
 * Return: the length of string
 */
int lenofstr(const char *string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	return (length);
}

