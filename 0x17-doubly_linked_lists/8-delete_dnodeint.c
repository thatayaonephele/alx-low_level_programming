#include "lists.h"
/**
 *delete_dnodeint_at_index - Deletes the node at index index of a linked list
 *@head: The head ptr pointing to the head of the double linked list
 *@index:The index of the node that should be deleted. Index starts at 0
 *
 *Return:1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int x = 0;
	dlistint_t *y;
	dlistint_t *z;

	z = *head;
	if (z) /*test if z is not pointing to null*/
	{
		while (z->prev) /*iterate when previous  z ptr is defined*/
			z = z->prev; /*set z to previous ptr eq to z */
	}
	while (z) /*iterate when z is not pointing to null*/
	{
		if (x == index) /*check if x matches index*/
		{
			if (x == 0) /*check if starting point of index is ok*/
			{
				*head = z->next; /*head ptr eq next ptr of z*/
				if (*head == NULL) /*if header ptr is defined*/
				{
					y->next = z->next; /*eq 2 next ptrs*/
					if (z->next == NULL) /*exist?*/
						z->next->prev = y;
				}
			}
			else
				(*head)->prev = NULL;/*h to prev ptr set to 0*/
			free(z); /*deallocate the dynamic memory from ptr*/
			return (1);
		}
		y = z;
		z = z->next; /*next ptr of z eq to z*/
		x++; /*increment the data int*/
	}
	return (-1);
}
