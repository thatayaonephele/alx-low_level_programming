#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - A function that frees a linked list's allocated memory.
 * @head: The adrr of the 1st/forward node of linked list listint
 * Return Always Success (0).
 **/

void free_listint(listint_t *head)
{
	listint_t *temp_node_1, *temp_node_2;

	for (temp_node_1 = head; temp_node_1 != NULL; temp_node_1 = temp_node_2)
	{
		temp_node_2 = temp_node_1->next;
		free(temp_node_1);
	}
}
