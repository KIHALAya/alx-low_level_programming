/* Author : KIHAL Aya */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>

#define ELF_MAGIC_SIZE 16

typedef struct {
	uint8_t magic[ELF_MAGIC_SIZE];
	uint8_t class;
	uint8_t data;
	uint8_t version;
	uint8_t os_abi;
	uint8_t abi_version;
	uint8_t padding[7];
	uint16_t type;
	uint16_t machine;
	uint32_t version2;
	uint64_t entry;
} ElfHeader;

/**
 * print_error - Print an error message to stderr and exit with status 98
 * @message: The error message to print
 */
void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header - Print the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 */
void print_elf_header(const ElfHeader *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < ELF_MAGIC_SIZE; i++) {
		printf("%02x ", header->magic[i]);
	}
	printf("\n");
	printf("  Class:                             ELF%d\n", (header->class == 1) ? 32 : 64);
	printf("  Data:                              2's complement, %s endian\n", (header->data == 1) ? "little" : "big");
	printf("  Version:                           %d (current)\n", header->version);
	printf("  OS/ABI:                            ");
	switch (header->os_abi) {
		case 0: printf("UNIX - System V\n"); break;
		case 6: printf("UNIX - Solaris\n"); break;
		case 7: printf("UNIX - AIX\n"); break;
		case 8: printf("UNIX - IRIX\n"); break;
		case 9: printf("UNIX - FreeBSD\n"); break;
		case 10: printf("UNIX - OpenBSD\n"); break;
		case 11: printf("UNIX - NetBSD\n"); break;
		case 12: printf("UNIX - GNU Hurd\n"); break;
		case 13: printf("UNIX - Linux\n"); break;
		case 14: printf("UNIX - GNU/kFreeBSD\n"); break;
		case 15: printf("UNIX - DragonFly\n"); break;
		default: printf("<unknown: %d>\n", header->os_abi);
	}
	printf("  ABI Version:                       %d\n", header->abi_version);
	printf("  Type:                              ");
	switch (header->type) {
		case 1: printf("REL (Relocatable file)\n"); break;
		case 2: printf("EXEC (Executable file)\n"); break;
		case 3: printf("DYN (Shared object file)\n"); break;
		default: printf("<unknown: %d>\n", header->type);
	}
	printf("  Entry point address:               0x%lx\n", header->entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	ElfHeader header;

	if (argc != 2) {
		print_error("Usage: elf_header elf_filename");
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		print_error("Error opening file");
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header)) {
		print_error("Error reading ELF header");
	}

	if (header.magic[0] != 0x7f || header.magic[1] != 'E' || header.magic[2] != 'L' || header.magic[3] != 'F') {
		print_error("Not an ELF file");
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}

