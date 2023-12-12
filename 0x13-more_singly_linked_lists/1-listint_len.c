#include "lists.h"

/**
 * listint_len - Print the number of elements in
 * a linked list.
 * @h: The head of a linked list.
 * Return: numbers of nodes on a linked list.
 */

size_t listint_len(const listint_t *h)
{
	size_t nth_nodes = 0;

	for (; h != NULL; nth_nodes++)
		h = h->next;
	return (nth_nodes);
}
