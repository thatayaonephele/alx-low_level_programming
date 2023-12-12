#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Delete a node at a given index of a linked list.
 * @head: A pointer to the 1st node.
 * @index: Delete position for linked node index.
 * Return: If succeeded: 1,else if it failed: -1.
 **/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node, *next;
	unsigned int x = 0;

	if (*head == NULL || head == NULL)
		return (-1);
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}
	current_node = *head;
	while (x < index - 1)
	{
		if (current_node->next != NULL)
			current_node = current_node->next;
		else
			return (-1);
		x++;
	}
	next = current_node->next;
	current_node->next = next->next;
	free(next);
	return (1);
}
