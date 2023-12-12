#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint -  the head node of a linked list is removed.
 * @head: 1st element in the linked list pointer
 * Return: Removed elememnt from linked list is displayed.
 * Else 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	int x;
	listint_t *temp_node;
	
	if (*head || head)
	{
		x = (*head)->n;
		temp_node = (*head)->next;
		free(*head);
		*head = temp_node;
		return (x);
	}
	return (0);
}
