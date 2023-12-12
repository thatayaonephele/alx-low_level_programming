#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Find a node in a list using 2 arguments
 * @head: A pointer pointing to first node of linked list's address
 * @index: The nth linked list node showing link position
 * Return: The nth linked list node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n;

	for (n = 0; head != NULL; n++)
	{
		if (n != index)
			head = head->next;
		return (head);
	}
	return (NULL);
}
