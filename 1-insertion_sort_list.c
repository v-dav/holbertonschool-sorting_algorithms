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
	listint_t *head = NULL;
	listint_t *j = NULL;

	if (list && *list)
	{
		head = *list;
		if ((*head)->next)
		{
			for (i = (*head)->next; i != NULL; i = (*head)->next->next)
			{
				for (j = i->prev; j != NULL; j = i->prev->prev)
				{
					if ((i->n) < (j->n))
					{
						/*changement des next et prev*/
						/*print*/
					}

				}
			}
		}
	}
}
