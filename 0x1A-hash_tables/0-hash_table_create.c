#include "hash_tables.h"

/**
 * hash_table_create - A function that creates a hash table
 * @size: The array size
 * Return:if successful - A ptr pointing to the new hash table
 * else a NULL ptr if the function fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long x = 0;
	hash_table_t *hashtable;

	hashtable = malloc(sizeof(hash_table_t)); /*dynamic mem alloc*/
	if (hashtable == NULL) /*test for malloc failure*/
		return (NULL);
	hashtable->size = size; /*set size ptr to size data*/
	hashtable->array = malloc(sizeof(hash_node_t *) * size); /*mem alloc*/
	if (hashtable->array == NULL) /*test for malloc failure*/
		return (NULL);
	for (; x < size; x++) /*iterate*/
		hashtable->array[x] = NULL; /*initialize at x index*/
	return (hashtable);
}
