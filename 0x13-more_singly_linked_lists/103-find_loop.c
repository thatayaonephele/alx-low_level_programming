#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: The pointer pointing to the start of the linked list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *i, *j;

	i = head;
	j = head;

	while (i && j && j->next)
	{
		i = i->next;
		j = j->next->next;
		if (i == j)
		{
			i = head;
			break;
		}
	}
	if (!j || !j->next  || !i)
		return (NULL);
	while (i != j)
	{
		i = i->next;
	j = j->next;
	}
	return (j);
}
