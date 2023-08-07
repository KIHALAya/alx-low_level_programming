/* Author : KIHAL Aya */
#include "main.h"


#define BUF_SIZE 1024

/**
 * main - Copy the content of a file to another file.
 *
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: On success, returns 0. On failure, exits with the corresponding error code.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t nread, nwrite;
    char buffer[BUF_SIZE];

    if (argc != 3)
    {
        dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1)
    {
        close(fd_from);
        dprintf(2, "Error: Can't write to file %s\n", argv[2]);
        exit(99);
    }

    while ((nread = read(fd_from, buffer, BUF_SIZE)) > 0)
    {
        nwrite = write(fd_to, buffer, nread);
        if (nwrite == -1 || nwrite != nread)
        {
            close(fd_from);
            close(fd_to);
            dprintf(2, "Error: Can't write to file %s\n", argv[2]);
            exit(99);
        }
    }

    if (nread == -1)
    {
        close(fd_from);
        close(fd_to);
        dprintf(2, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    if (close(fd_from) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}

