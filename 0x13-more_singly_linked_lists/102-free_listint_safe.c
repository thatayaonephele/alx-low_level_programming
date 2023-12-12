#include "lists.h"

/**
 * free_listint_safe - Frees the structure memory of listint_t lists with loops
 * @h: The pointer pointing to the linked list listint_t head address
 * Return: The size of the list that was free'd.
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *temp_node;
	size_t x = 0;
	size_t my_node;

	my_node = listint_len(*h);
	if (my_node != 0)
	{
		while (x < my_node)
		{
			temp_node = (*h)->next;
			free(*h);
			*h = temp_node;
			x++;
		}
		*h = NULL;
		}
		else
		{
			while ((*h != NULL) && (h != NULL))
			{
				temp_node = (*h)->next;
				free(*h);
				*h = temp_node;
				my_node++;
			}
		}
		h = NULL;
	return (my_node);
}
