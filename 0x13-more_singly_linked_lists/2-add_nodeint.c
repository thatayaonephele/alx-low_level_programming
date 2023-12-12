#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - Append a node that is new at the beginning
 * of a linked list
 * @head: The head of a list that is linked.
 * @n: n The nth element.
 * Return: The address of the new element,or NUll if it failed.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (!(new_node == NULL))
	{
		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
	}
	else
		return (NULL);

	return (*head);
}
