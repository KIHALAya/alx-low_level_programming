/* Author : KIHAL Aya */
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Pointer to the pointer of the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *temp;

	if (h == NULL)
		return (0);

	while (*h != NULL)
	{
		size++;
		if (*h <= (*h)->next)
		{
			*h = NULL;
			break;
		}
		temp = (*h)->next;
		free(*h);
		*h = temp;
	}

	return (size);
}

