#include "hash_tables.h"

/**
 *hash_table_delete - A function that deletes a hash table.
 *@hashtable: A ptr pointing to the hash table.
 *Return: Nothing (void function).
 */
void hash_table_delete(hash_table_t *hashtable)
{
	unsigned long x = 0;
	hash_node_t *node, *temp;
	hash_table_t *h = hashtable;

	while (x < hashtable->size) /*iterate*/
	{
		if (hashtable->array[x] != NULL) /*test if we at head node || NULL*/
		{
			node = hashtable->array[x]; /*init hashtable@index x*/
		for (; node != NULL; node = temp) /*iterate*/
		{
			temp = node->next; /*init node next ptr*/
			free(node->key);  /*deallocate mem*/
			free(node->value); /*deallocate mem*/
			free(node); /*deallocate mem*/
		}
	}
	x++;
	}
	free(h->array); /*deallocate mem*/
	free(h); /*deallocate mem*/
}
