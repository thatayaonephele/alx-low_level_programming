#include "hash_tables.h"

void shash_table_delete(shash_table_t *ht);
shash_table_t *shash_table_create(unsigned long int size);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_print(const shash_table_t *ht);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);


/**
 * shash_table_create - Creates a hash table.
 * @size: the size of the array
 * Return: NULL on error
 * else - A pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int x = 0;
	shash_table_t *ht;

	ht = malloc(sizeof(shash_table_t)); /*dynamic mem alloc*/
	if (ht == NULL) /*test for malloc failuire*/
		return (NULL);

	ht->size = size;/*init data ptr*/
	ht->array = malloc(sizeof(shash_node_t *) * size); /*dynamic mem alloc*/
	if (ht->array == NULL) /*test for malloc failuire*/
		return (NULL);
	while (x < size)
	{
		ht->array[x] = NULL;
		x++;
	}
	ht->stail = NULL;
	ht->shead = NULL;

	return (ht);
}
/**
 *shash_table_set - A function that adds an element to the hash table
 *@ht: A ptr pointing to the hash table
 *@key: The key to add - must be duplicated & can be an empty string
 *@value: The value associated with key.
 *Return: 1 if it succeeded, 0 otherwise
 *In case of collision, add the new node at the beginning of the list
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int pos;
	char *v_c;
	shash_node_t *temp, *new;

	if (key == NULL || ht == NULL || value == NULL || *key == '\0')
		return (0);

	v_c = strdup(value); /*init vc by duplicating the value*/
	if (v_c == NULL) /*test if string duplication successful*/
		return (0);

	pos = key_index((const unsigned char *)key, ht->size); /*init pos*/
	temp = ht->shead; /*init the hashtable sorted head*/
	while (temp) /*iterate as long temp node is defined*/
	{
		if (strcmp(temp->key, key) == 0) /*lexigraphic cmp for key*/
		{
			free(temp->value); /*deallocate mem*/
			temp->value = v_c;
			return (1); /*successful return*/
		}
		temp = temp->snext; /*temp node set to sorted next ptr*/
	}

	new = malloc(sizeof(shash_node_t)); /*dynamic mem alloc*/
	if (new == NULL) /*test for malloc failuire*/
	{
		free(v_c);/*deallocate mem*/
		return (0);
	}
	new->key = strdup(key);/*make a string duplication of key*/
	if (new->key == NULL) /*check if string dup was successful*/
	{
		free(v_c); /*deallocate mem*/
		free(new); /*deallocate mem*/
		return (0);
	}
	new->value = v_c;
	new->next = ht->array[pos];
	ht->array[pos] = new;

	if (strcmp(ht->shead->key, key) > 0) /*do lexi cmp on key*/
	{
		new->snext = ht->shead;
		new->sprev = NULL;
		ht->shead = new;
		ht->shead->sprev = new;
	}
	else if (ht->shead == NULL)
	{
		new->sprev = NULL; /*re-init the sorted pre ptr*/
		new->snext = NULL; /*re-init the sorted next ptr*/
		ht->stail = new;
		ht->shead = new;
	}
	else
	{
		temp = ht->shead; /*re-init sorted head node ptr*/
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new->sprev = temp;
		new->snext = temp->snext;
		if (temp->snext != NULL)
			temp->snext->sprev = new; /*reinit new ptr*/
		else
			ht->stail = new;
		temp->snext = new;
	}
	return (1); /*successful return*/
}
/**
 * shash_table_delete - Function that deletes a hash table.
 * @ht: A ptr to the hash table.
 *Return: Nothing (void function)
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;
	shash_table_t *head = ht;

	if (ht == NULL) /*test for header node*/
		return;

	node = ht->shead;
	for (; node; node = temp)
	{
		temp = node->snext;
		free(node->key); /*deallocate mem*/
		free(node->value); /*deallocate mem*/
		free(node); /*deallocate mem*/
	}

	free(head->array); /*deallocate mem*/
	free(head); /*deallocate mem*/
}
/**
 * shash_table_print_rev - Function that prints a sorted reveresed hash table
 * @ht: A ptr pointing to the hash table(now sorted) to displayed
 *Return: Nothing (void function)
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *my_n;

	if (ht == NULL) /*check if func init*/
		return;
	my_n = ht->stail; /*init sorted tail ptr*/
	printf("{");
	while (my_n != NULL) /*iterate if I'm not at Head node*/
	{
		printf("'%s': '%s'", my_n->key, my_n->value);
		my_n = my_n->sprev; /*init sorted prev ptr*/
		if (my_n != NULL) /*test if I'm at head node*/
			printf(", "); /*add delimeter*/
	}
	printf("}\n");
}

/**
 * shash_table_get - Function that retrieves a value associated with a key
 * @ht: A ptr pointing to the now sorted hash table
 * @key: The key to get the value of.
 * Return: NULL for unsuccessful match
 * else - The value associated with a key
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long pos;
	shash_node_t *my_n;

	if (ht == NULL || *key == '\0' || key == NULL)
		return (NULL);

	pos = key_index((const unsigned char *)key, ht->size);
	if (pos >= ht->size) /*test for pos matching hash table size ptr*/
		return (NULL);

	my_n = ht->shead; /*init sorted head node*/
	while (my_n != NULL && strcmp(my_n->key, key) != 0) /*iterate with lexi cmp*/
		my_n = my_n->snext; /*set node to sorted next ptr*/

	if (my_n == NULL) /*head node test*/
		return (NULL);
	else
		return (my_n->value);
}
/**
 * shash_table_print - print the key/value in the order that
 *they appear in the array of hash table
 * @ht: A ptr pointing to the now sorted hash table
 *Return: Nothing (void function)
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *my_n;

	if (ht == NULL) /*test if we at hashtable defined*/
		return;

	my_n = ht->shead; /*init the sorted hashtable head node*/
	printf("{");
	for (; my_n != NULL; my_n = my_n->snext)
	{
		printf("'%s': '%s'", my_n->key, my_n->value);
		if (my_n != NULL)
			printf(", ");
	}
	printf("}\n");
}
