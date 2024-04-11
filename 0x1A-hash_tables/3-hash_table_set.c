#include "hash_tables.h"

/**
 *hash_table_set - A function that adds an element to the hash table
 *@ht: A ptr pointing to the hash table
 *@key: The key to add - must be duplicated & can be an empty string
 *@value: The value associated with key.
 *Return: 1 if it succeeded, 0 otherwise
 *In case of collision, add the new node at the beginning of the list
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long x;
	hash_node_t *new;
	unsigned long pos;
	char *v_c;

	if (key == NULL || ht == NULL || *key == '\0' || value == NULL)
		return (0);
	v_c = strdup(value);
	if (v_c == NULL)
		return (0);
	pos = key_index((const unsigned char *)key, ht->size);
	x = pos;
	while (ht->array[x])
	{
		if (strcmp(ht->array[x]->key, key) == 0) /*lexigraphic cmp*/
		{
			free(ht->array[x]->value); /*deallocation of memory*/
			ht->array[x]->value = v_c;
			return (1);
		}
		x++; /*increment to next pos*/
	}
	new = malloc(sizeof(hash_node_t)); /*dynamic mem alloc*/
	if (new == NULL) /*test for malloc failure*/
	{
		free(v_c); /*deallocation of memory*/
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new); /*deallocation of memory*/
		return (0);
	}
	new->value = v_c;
	new->next = ht->array[pos];
	ht->array[pos] = new;
	return (1);
}
