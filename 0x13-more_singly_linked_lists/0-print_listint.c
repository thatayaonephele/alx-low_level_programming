#include <stdio.h>
#include "lists.h"

/**
 * print_listint - All the elements of a single linked list are printed
 * @h: The head node of the list
 * Return: Number of nodes
 */

size_t print_listint(const listint_t *h)
{
const listint_t *my_cursor = h;
size_t counter = 0;

for (; my_cursor != NULL; counter++)
{

	printf("%d\n", my_cursor->n);
	my_cursor = my_cursor->next;
}
return (counter);
}
