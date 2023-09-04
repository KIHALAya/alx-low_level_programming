/* Author : KIHAL Aya */
#include "main.h"

/**
 * read_textfile -  reads a text file and prints it to the standard output.
 * @filename: the path to the file from which we want to read data.
 * @letters: size of the data read and to be written to the standard output.
 *
 * Return: On Success, returns the number of bytes read, written.
 *         On Failure, returns 0 to indicate an error.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd = -1;
	ssize_t  bytes_read;
	ssize_t  bytes_written;
	void *buf = malloc(letters);

	if (!buf)
	{
		perror("malloc");
		close(fd);
		return (0);
	}

	if (filename != NULL)
	{
		fd = open(filename, O_RDONLY);
		if (fd != -1)
		{
			bytes_read = read(fd, buf, letters);
			if (bytes_read != -1)
			{
				bytes_written = write(STDOUT_FILENO, buf, bytes_read);
				if (bytes_written != -1)
				{
					free(buf);
					close(fd);
				}	return (bytes_written);
			}
		}
	}
	free(buf);
	if (fd != -1)
		close(fd);
	return (0);
}
