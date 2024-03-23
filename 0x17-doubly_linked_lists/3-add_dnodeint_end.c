#include "lists.h"
/**
 *add_dnodeint_end -adds a new node at the end of a dlistint_t list
 *@head:The head of the linked list
 *@n:The integer data of the double linked list
 *Return:the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *lagg;
	dlistint_t *temp;

	temp = malloc(sizeof(dlistint_t)); /*initialization of temp ptr*/
	if (!temp) /*test if dynamic memory allocation was succcessful*/
		return (NULL);
	temp->n = n; /*temp ptr to data set to struct data*/
	temp->next = NULL; /*initialization of tempt ptr to next node*/

	if (!*head)
	{
		temp->prev = NULL; /*double linked list*/
		*head = temp; /*point head to double linked list*/
		return (temp);
	}
	lagg = *head;/*point lag to head*/
	while (lagg->next != NULL) /*as long as next of lag ins't NULL*/
		lagg = lagg->next;
	lagg->next = temp;
	temp->prev = lagg;/*swap*/
	return (temp);

}
