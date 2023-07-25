#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to a pointer to the head of the list.
 * @node: Pointer to the node to be swapped.
 */
static void swap_nodes(listint_t **list, listint_t *node)
{
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	if (node->next)
		node->next->prev = node->prev;

	node->next = node->prev;
	node->prev = node->next->prev;
	node->next->prev = node;

	if (node->prev)
		node->prev->next = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		/* Forward pass: Bubble sort from left to right */
		for (tmp = *list; tmp->next != NULL; tmp = tmp->next)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		/* Backward pass: Bubble sort from right to left */
		for (tmp = tmp->prev; tmp->prev != NULL; tmp = tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}
