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
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file to append to.
 * @text_content: a NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_result;
	int append_flag = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);


	if (lseek(fd, 0, SEEK_CUR) == -1)
	{

		append_flag = 0;
	}
	else
	{
		append_flag = 1;
	}

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

	if (append_flag == 1)
		return (1);
	else
		return (-1);
}

