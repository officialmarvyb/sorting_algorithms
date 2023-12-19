#include "sort.h"

/**
 * swap_nodes - function to swap the nodes
 * @list: double pointer to hold the first node
 * @node1: is a pointer to hold any other secondary node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	/* Swap the positions of two nodes in a linked list */
	if (node1 == node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - function to swap a doubly linked list
 * @list: double pointer that points to the first node
 */

void insertion_sort_list(listint_t **list)
{
	/* Perform an insertion sort on a linked list */
	listint_t *current = NULL, *tmp = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;

		while (tmp && tmp->prev && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}

		current = current->next;
	}
}
