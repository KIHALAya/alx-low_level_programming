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

/**
 * create_file - creates a file.
 * @filename: name of the file to be created.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_result;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		write_result = write(fd, text_content, lenofstr(text_content));
		if (write_result == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

