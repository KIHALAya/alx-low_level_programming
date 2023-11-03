#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head_table = ht;
	hash_node_t *current_node, *temp_node;
	unsigned long int index;

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			current_node = ht->array[index];
			while (current_node != NULL)
			{
				temp_node = current_node->next;
				free(current_node->key);
				free(current_node->value);
				free(current_node);
				current_node = temp_node;
			}
		}
	}
	free(head_table->array);
	free(head_table);
}

