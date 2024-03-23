#include "lists.h"

/**
 * get_dnodeint_at_index -returns the nth node of a dlistint_t linked list
 * @head: The head of the double linked list
 * @index: The index postion of the double linked list
 * Return:if the node does not exist, return NULL
 * else the nth node of the double linked list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index != 0)
	{
		if (!head) /*if head ptr points to NULL ptr*/
			return (NULL);
		head = head->next; /*set head to next ptr of head*/
		index--; /*decrement index till zero*/
	}
	return (head);
}
