#include "lists.h"
/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 *@head:The head of the double linked list
 *@n:The integer data parameter of the double linked list
 *
 *Return:the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *x;

	x = malloc(sizeof(dlistint_t));
	if (!x) /*test if dynamic memory allocation was successful*/
		return (NULL);
	x->n = n; /*set struct data to new ptr*/
	x->next = *head; /*point the next node to the head of list*/
	if (*head) /*if head isnt pointing to NULL*/
		(*head)->prev = x; /*point the previous of head to new ptr*/
	*head = x;
	return (x);

}
