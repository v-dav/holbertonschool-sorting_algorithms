#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: a pointer to the pointer to the head of a doubly linked list
 * that needs to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i = NULL;
	listint_t *j = NULL;

	if (list == NULL || *list == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = i->next)
	{
		for (j = i->prev; j != NULL; j = j->prev)
		{
			if ((i->n) < (j->n))
			{
				/* i is not the last element in the list */
				if (i->next)
					i->next->prev = j;

				/* j is not the first element in the list */
				if (j->prev)
					j->prev->next = i;
				else /* j is the first element, update the head of the list */
					*list = i;

				/* Swap i and j */
				i->prev = j->prev;
				j->next = i->next;
				i->next = j;
				j->prev = i;

				/* Print the list */
				print_list(*list);
			}
		}
	}
}
