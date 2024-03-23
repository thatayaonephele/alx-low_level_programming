#include "lists.h"
/**
*sum_dlistint - return the sum of all the data (n) of a dlistint_t linked list
*@head: The head ptr of the double linked list
*
*Return: if the list is empty, return 0, else return sum
*/
int sum_dlistint(dlistint_t *head)
{
	int x = 0;
	dlistint_t *current_node = head;

	if (head == NULL) /*if head ptr isn't defined*/
		return (x);
	for (; current_node; current_node = current_node->next)
		x = x + current_node->n; /*set x to x + n data of curr node*/
	return (x); /*Return the sum of int data*/
}
