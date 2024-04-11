#include "hash_tables.h"

/**
 *hash_table_print - function that prints a hash table.
 *@ht: A ptr pointing to the hash table.
 *Return: Nothing (void function)
 */
void hash_table_print(const hash_table_t *ht)
{
	char *del = "";
	hash_node_t *my_node;
	unsigned long x = 0;

	if (!ht || !ht->array)
		return;
	printf("{");
	for (; x < ht->size; x++)
	{
		my_node = ((ht->array)[x]);
		for (; my_node; my_node = my_node->next)
		{
			printf("%s'%s': '%s'", del, my_node->key, my_node->value);
			del = ", ";
		}
	}
	printf("}\n");
}
