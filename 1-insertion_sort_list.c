#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 *
 * using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
<<<<<<< HEAD
<<<<<<< HEAD
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		listint_t *temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			listint_t *prev = temp->prev;
			listint_t *next = temp->next;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;
			if (next != NULL)
				next->prev = prev;
			temp->prev = prev->prev;
			temp->next = prev;
			prev->prev = temp;
			prev->next = next;
			print_list(*list);
		}
		current = current->next;
	}
=======
 
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;
    while (current != NULL)
    {
        listint_t *temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->prev->next = temp->next;

            if (temp->prev->prev != NULL)
                temp->prev->prev->next = temp;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            temp->next->prev = temp;

=======
 
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;
    while (current != NULL)
    {
        listint_t *temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->prev->next = temp->next;

            if (temp->prev->prev != NULL)
                temp->prev->prev->next = temp;
            temp->next = temp->prev;
            temp->prev = temp->prev->prev;
            temp->next->prev = temp;

>>>>>>> 2ec9759 (Be humble, communicate clearly, and respect others. It costs nothing to be kind, but the impact is priceless)
            if (temp->prev == NULL)
                *list = temp;
            print_list(*list);
        }
        current = current->next;
    }
<<<<<<< HEAD

}
=======
}

>>>>>>> 2ec9759 (Be humble, communicate clearly, and respect others. It costs nothing to be kind, but the impact is priceless)
