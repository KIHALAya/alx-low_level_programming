#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given index.
 * @head: Pointer to a pointer to the head of the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
		free(current);
		return (1);
	}

	while (index > 1 && current != NULL)
	{
		current = current->next;
		index--;
	}

	if (current == NULL || current->next == NULL)
		return (-1);

	current->next = current->next->next;
	if (current->next != NULL)
		current->next->prev = current;
	return (1);
}

