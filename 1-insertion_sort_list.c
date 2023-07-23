#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked
 * @list: Pointer to the head of the doubly linked list
 */
 
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

            if (temp->prev == NULL)
                *list = temp;
            print_list(*list);
        }
        current = current->next;
    }
}

