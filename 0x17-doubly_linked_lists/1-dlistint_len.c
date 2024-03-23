#include "lists.h"
/**
 *dlistint_len- a function that returns the no. of elements in a linked list
 *@h: The head of the double linked list
 *Return: the number of elements in a linked dlistint_t list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t data;

	data = 0;
	while ((!h) == false)
	{
		data++;
		h = h->next;
	}
	return (data);
}
