/*Realized by : KIHAL Aya*/
#include <stdio.h>
#include "main.h"
/**
  * main - print the first 50 fibonacci numbers.
  * Return: Nothing.
  */
int main(void)
{
	int i, sum = 0;

	for (i = 0; i < 1024; i++)
	{
		if ((i % 3) == 0 || (i % 5) == 0)
			sum += i;
	}

	printf("%d\n", sum);

	return (0);
}
