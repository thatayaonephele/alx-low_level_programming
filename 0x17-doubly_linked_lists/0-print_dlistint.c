#include "lists.h"
/**
 *print_dlistint - Prints all the elements of a dlistint_t list
 *@h: The head of the double linked list
 *
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t data = 0;
	const dlistint_t *new = h;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
		data++;
	}
	return (data);
}
