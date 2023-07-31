/* Author : KIHAL Aya */
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: pointer to the head of the list.
 * Return: the number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current;

	for (current = h; current != NULL; current = current->next)
	{
		printf("%d\n", current->n);
		count++;
	}

	return (count);

}
