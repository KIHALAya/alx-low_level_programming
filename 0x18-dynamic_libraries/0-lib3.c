#include "main.h"

/**
 * _strcpy - Copy one string to another.
 * @dest: The destination buffer to copy to.
 * @src: The source string to copy from.
 *
 * Return: A pointer to the destination buffer.
 */

char *_strcpy(char *dest, char *src)
{
	size_t i;
	size_t length = _strlen(src);

	for (i = 0; i < length && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strcat - Concatenate a specified number of characters from one
 * string to a other.
 * @dest: The destination buffer to concatenate to.
 * @src: The source string to concatenate from.
 *
 * Return: A pointer to the destination buffer.
 */

char *_strcat(char *dest,  char *src)
{
	size_t len = _strlen(dest);
	size_t i;

	for (i = 0; i < len && src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}


/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

/**
 * _strcmp - Compare the first n characters of two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater than zero if the first n
 * characters of str1 are found, respectively, to be less than, to match,
 * or be greater than the first n characters of str2.
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _memset - set a block of memory to a specific value.
 * @s: pointer to the memory block to fill with a specific value.
 * @b: the value that you want to set in the memory block.
 * @n: The number of bytes to set to the specified value.
 * Return: pointer to the modified block of memory.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
