/* Author : KIHAL Aya */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * open_file - Open a file and handle errors.
 * @file: The name of the file to open.
 * @flags: Flags for opening the file.
 * @mode: Permissions to set if the file is created.
 *
 * Return: The file descriptor.
 */
int open_file(const char *file, int flags, mode_t mode)
{
	int fd = open(file, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(98);
	}
	return (fd);
}

/**
 * copy_content - Copy the content of one file to another.
 * @src: The source file name.
 * @dest: The destination file name.
 */
void copy_content(const char *src, const char *dest)
{
	int src_fd = open_file(src, O_RDONLY, 0664);
	int dest_fd = open_file(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	close(src_fd);
	close(dest_fd);
}

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	copy_content(argv[1], argv[2]);

	return (0);
}

