#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a list.
 * @head: 1st linked list node address.
 * @n: The index position showing were node should be inserted
 * Return: The address of the new element, or Null if it failed.
 **/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp_node_1, *temp_node_2;

	temp_node_1 = malloc(sizeof(listint_t));
	if (temp_node_1 != NULL)
	{
		temp_node_1->n = n;
		temp_node_1->next = NULL;
	}
	else
		return (NULL);
	if (*head == NULL)
	{
		*head = temp_node_1;
		return (temp_node_1);
	}
	for (temp_node_2 = *head; temp_node_2->next; )
		temp_node_2 = temp_node_2->next;
	temp_node_2->next = temp_node_1;
	return (temp_node_1);
}
