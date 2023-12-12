#include "lists.h"
/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @head: The pointer pointing to the head of the listint_t to be searched
 * Return: Always Success (0)
 */
size_t listint_len(const listint_t *head)
{
	size_t my_node = 1;
	const listint_t *animal_1, *animal_2;

	if (head != NULL || head->next != NULL)
	{
		animal_2 = head->next;
		animal_1 = (head->next)->next;
		while (animal_1)
		{
			if (animal_2 == animal_1)
			{
				animal_2 = head;
				for (; animal_2 != animal_1; my_node++)
				{
					animal_2 = animal_2->next;
					animal_1 = animal_1->next;
				}
				animal_2 = animal_2->next;
				for (my_node = 1; animal_2 != animal_1; my_node++)
					animal_2 = animal_2->next;
				return (my_node);
			}
			animal_2 = animal_2->next;
			animal_1 = (animal_1->next)->next;
		}
		return (0);
	}
	else
		return (0);
}
/**
 * print_listint_safe - Prints a linked list listint_t (safe version)
 * @head: A pointer pointing to the head of the linked list listint_t.
 * Return: The number of nodes in the list if succcessful,
 * else exit the program with status 98 on failiure
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t x = 0; /* The index*/
	size_t my_node; /*The actual nodes*/

	my_node = listint_len(head);
	if (my_node != 0)
	{
		while (x < my_node)
		{
			printf("[%p] %d\n", (V_P)head, head->n);
			head = head->next;
			x++;
		}
		printf("-> [%p] %d\n", (V_P)head, head->n);
	}
	else
	{
		while (head != NULL)
		{
			printf("[%p] %d\n", (V_P)head, head->n);
			head = head->next;
			my_node++;
		}
	}
	return (my_node);
}
