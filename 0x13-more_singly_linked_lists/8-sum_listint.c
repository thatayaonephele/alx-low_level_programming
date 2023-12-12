#include "lists.h"
/**
 * sum_listint - Displays the summation of all the data(n)
 * @head: The linked list to be summed up.
 * Return: The summation of all the data, else 0 if list is empty.
 */
int sum_listint(listint_t *head)
{
	listint_t *temp_node_link;
	int sum_all_data = 0;

	if (head != NULL)
	{
		temp_node_link = head;
		while (temp_node_link != NULL)
		{
			sum_all_data += temp_node_link->n;
			temp_node_link = temp_node_link->next;
		}
		return (sum_all_data);
	}
	else
		return (0);
}
