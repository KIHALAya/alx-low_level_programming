#include "main.h"

/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: input value.
 *
 * Return: 1 if digit else 0 (False)
 *
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * _strlen - return the length of string.
 * @string: string we desire determin the length of.
 *
 * Return: the length of string
 */

int _strlen(char *string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strncpy - Copy a specified number of characters from one string to another.
 * @dest: The destination buffer to copy to.
 * @src: The source string to copy from.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination buffer.
 */

char *_strncpy(char *dest, char *src, int  n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}

/**
 * _strncat - Concatenate a specified number of characters from one
 * string to a other.
 * @dest: The destination buffer to concatenate to.
 * @src: The source string to concatenate from.
 * @n: The maximum number of characters to concatenate.
 *
 * Return: A pointer to the destination buffer.
 */

char *_strncat(char *dest,  char *src, int n)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _puts - outputting strings to the output standard.
 * @s: the string to be output.
 */
void _puts(char *s)
{
	printf("%s\n", s);
}
