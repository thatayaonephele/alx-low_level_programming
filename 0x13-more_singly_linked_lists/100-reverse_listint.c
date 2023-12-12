#include "lists.h"

/**
 * reverse_listint - A function that reverses a listint_t list.
 * @head: A pointer to the address
 * of the head of the list_t list.
 * Return: A pointer to the 1st node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *lagging_node, *foward_node;

	if (*head != NULL || head != NULL)
	{
		lagging_node = NULL;
		for (; (*head)->next != NULL; *head = foward_node)
	{
		foward_node = (*head)->next;
		(*head)->next = lagging_node;
		lagging_node = *head;
	}
	(*head)->next = lagging_node;
	return (*head);
	}
	else
		return (NULL);
}
