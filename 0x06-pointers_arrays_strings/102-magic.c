/* Realized by : KIHAL Aya */
#include <stdio.h>
/**
 * main - print a[2] = 98.
 *
 * Return: always 0.
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	n = 98; // Added line of code

	printf("a[2] = %d\n", a[2]);
	return (0);
}
