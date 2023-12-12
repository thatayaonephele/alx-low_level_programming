#include "lists.h"
#include <stdlib.h>
/**
 * insert_nodeint_at_index - Add a new node to a
 * listint_t list based on a new list
 * @head: A pointer pointing to head of the listint_t list address.
 * @idx: Index position of the listint_t list where the new node should be
 * added on linked list with indices starting at 0.
 * @n: The integer value new node will hold.
 * Return: If the function evaluates to logical true
 * - the address of the new node. Else - NULL.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int my_node_link;
	listint_t *new_link_list, *temp_node = *head;

	new_link_list = malloc(sizeof(listint_t));
	if (new_link_list != NULL)
	{
		new_link_list->n = n;
		if (idx == 0)
	{
		new_link_list->next = temp_node;
		*head = new_link_list;
		return (new_link_list);
	}
	my_node_link = 0;
	while (my_node_link < (idx - 1))
	{
		if (temp_node->next != NULL || temp_node != NULL)
		{
			temp_node = temp_node->next;
			my_node_link++;
		}
		else
			return (NULL);
		}
		new_link_list->next = temp_node->next;
		temp_node->next = new_link_list;
		return (new_link_list);
		}
	else
		return (NULL);
}
