#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the array
 *
 * Return: Pointer to the newly created sorted hash table, NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_table = malloc(sizeof(shash_table_t));
	unsigned long int i;

	if (hash_table == NULL)
		return (NULL);
	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_node_t *) * size);
	hash_table->shead = NULL;
	hash_table->stail = NULL;
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	for (i = 0; i < size; ++i)
	{
		hash_table->array[i] = NULL;
	}
	return (hash_table);
}

/**
 * shash_table_set - Inserts a key/value pair into a sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: The key string
 * @value: The value string
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *new_node = malloc(sizeof(shash_node_t));

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	if (ht->array[index] != NULL)
		ht->array[index]->sprev = new_node;
	ht->array[index] = new_node;

	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		new_node->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = new_node;
		ht->shead = new_node;
	} else
	{
		shash_node_t *temp = ht->shead;

		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
		{
			temp = temp->snext;
		}
		new_node->snext = temp->snext;
		if (temp->snext != NULL)
			temp->snext->sprev = new_node;
		temp->snext = new_node;
		new_node->sprev = temp;
	}
	if (new_node->snext == NULL)
		ht->stail = new_node;
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with
 * a key in the sorted hash table
 * @ht: Pointer to the sorted hash table
 * @key: The key to get the value of
 *
 * Return: The value associated with key in ht, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *current_node = ht->array[index];

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table
 * using the sorted linked list
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node = ht->shead;

	if (ht == NULL)
		return;
	printf("{");
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table
 * in reverse order using the sorted linked list
 * @ht: Pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node = ht->stail;

	if (ht == NULL)
		return;
	printf("{");
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: Pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current_node, *temp_node;
	unsigned long int i;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];
		while (current_node != NULL)
		{
			temp_node = current_node->next;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
			current_node = temp_node;
		}
	}

	free(ht->array);
	free(ht);
}

