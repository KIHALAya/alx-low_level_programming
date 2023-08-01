/* Author : KIHAL Aya */
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely (detects cycles).
 * @head: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *node1, *node2;
	size_t count = 0;

	node1 = head;
	node2 = head;

	while (node1 != NULL && node2 != NULL && node2->next != NULL)
	{
		node1 = node1->next;
		node2 = node2->next->next;

		if (node1 == node2)
		{
			printf("-> [%p] %d\n", (void *)node1, node1->n);
			return count; /* Return the number of nodes encountered so far */
		}

		printf("[%p] %d\n", (void *)node1, node1->n);
		count++;
	}

	return count;
}

