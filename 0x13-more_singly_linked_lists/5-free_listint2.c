#include "lists.h"
#include <stdlib.h>

/**
  * free_listint2 - Frees a linked lists' memory allocation
  * by setitng the head to NULL.
  * @head: The initial node of the linked list
  * Return: Always Success (0).
  */

void free_listint2(listint_t **head)
{
	listint_t *temp_link_node;

	if (head != NULL)
	{
		for (; *head; *head = temp_link_node)
		{
			temp_link_node = (*head)->next;
			free(*head);
		}
		*head = NULL;
	}
	else
		return;
}
