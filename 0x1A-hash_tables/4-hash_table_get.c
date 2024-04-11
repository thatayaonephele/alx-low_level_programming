#include "hash_tables.h"

/**
 *hash_table_get - A function that retrieves a value associated with a key.
 *@ht: A ptr pointing to the hash table.
 *@key: The key to add - cannot be an empty string.
 *Return: Val associated with the element, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long pos;
	hash_node_t *my_node;

	if (key == NULL || ht == NULL) /*test eof, head node*/
		return (NULL);
	pos = key_index((const unsigned char *)key, ht->size);
	if (ht->array[pos] == NULL)
		return (NULL);
	my_node = ht->array[pos];
	while (my_node != NULL)
	{
		if ((strcmp(my_node->key, key) == 0))
			return (my_node->value);
		my_node = my_node->next;
	}
		return (NULL);
}
