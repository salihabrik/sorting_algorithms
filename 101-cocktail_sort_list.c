#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;

    if (node1->prev == NULL)
        *list = node1;
    if (node2->prev == NULL)
        *list = node2;
}

void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *curr;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do
    {
        swapped = 0;
        for (curr = *list; curr->next != NULL; curr = curr->next)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(list, curr, curr->next);
                print_list(*list);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
        swapped = 0;
        for (curr = curr->prev; curr->prev != NULL; curr = curr->prev)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(list, curr->prev, curr);
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}

