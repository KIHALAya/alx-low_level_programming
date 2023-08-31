/* Author : KIHAL Aya */
#include "main.h"
/**
 * get_endianness - check the endianness of the system.
 * Return: Returns 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endianCheck = (char *)&num;

	return (*endianCheck == 1);
}

