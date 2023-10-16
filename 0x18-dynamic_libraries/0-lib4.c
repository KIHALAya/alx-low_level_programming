#include "main.h"

/**
 * _atoi - Convert a string into an integer data type.
 * @s: The string to convert.
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int num = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
		} else
		{
			break;
		}
		i++;
	}

	return (num * sign);
}

/**
 * _memcpy - Copy a block of memory from one location to another.
 * @dest: The destination memory location.
 * @src: The source memory location.
 * @n: The number of bytes to copy.
 * Return: A pointer to the destination memory location.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];


	return (dest);
}

/**
 * _strspn - calculate the length of a prefix substring.
 * @s: The string for which you want to calculate the length of the substring.
 * @accept: The set of characters that define the allowed prefix.
 * Return: the length of a prefix substring.
 */
unsigned int _strspn(char *s, char *accept)
{
	size_t length = 0;
	int found = 0;

	while (*s)
	{
		const char *a = accept;

		for (a; *a; a++)
		{
			if (*s == *a)
			{
				found = 1;
				break;
			}
		}

		if (found)
		{
			length++;
			s++;
		}
		else
			break;

	}

	return (length);
}

/**
 * *_strpbrk - searches for  a set of bytes in a string
 * @s: string to search
 * @accept: stringof  the bytes to look for
 * Return: pointer to the byte in s that matches one of the bytes in accept
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; *s != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (*s == accept[j])
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}

/**
 * *_strstr - search for a substring in a string
 * @haystack: string to search in
 * @needle: substring to look for
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}
