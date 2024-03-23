#include "lists.h"
/**
 *insert_dnodeint_at_index-function that inserts a new node at a given pos
 *@h:The head ptr pointing to the head of the double linked list
 *@idx:The index of the list where the new node should be added,starting at 0
 *@n:The integer data type of the double linked list
 *
 *Return:the address of the new node, or NULL if it failed
 *if it is not possible to add the new node at index idx,
 *do not add the new node and return NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = *h, *n_n;

	if (idx == 0) /*if index position is 0*/
		return (add_dnodeint(h, n));
	while (idx != 1)
	{
		new = new->next; /*set new to next ptr of new*/
		if (!new) /*if new temp node points to NULL*/
			return (NULL);
		idx--;
	}
	if (new->next == NULL) /*if next of new temp is undefined*/
		return (add_dnodeint_end(h, n));
	n_n = malloc(sizeof(dlistint_t));
	if (!n_n) /*test if dynamic mem alloc was successful*/
		return (NULL);
	n_n->n = n; /*set new node data struct n to int data n*/
	n_n->prev = new; /*set new node prev ptr to new temp node*/
	n_n->next = new->next; /*set next of new node to next of new temp*/
	new->next->prev = n_n; /*set prev of next ptr to new node*/
	new->next = n_n; /*set next ptr of new temp node to new node data*/
	return (n_n);
}
