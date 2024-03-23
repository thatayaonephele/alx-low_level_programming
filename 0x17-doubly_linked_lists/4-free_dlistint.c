#include "lists.h"
/**
 * free_dlistint -a function that frees a dlistint_t list
 * @head: The head of the double linked list
 *
 *Return: Nothing (Void Function)
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *x;

	while (head)
	{
		x = head->next; /*set x to next of head ptr*/
		free(head);
		head = x;
	}
}
