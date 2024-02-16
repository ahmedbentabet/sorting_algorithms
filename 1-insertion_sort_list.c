#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
*
* @list: Pointer to a pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *traverse;

	/* Check for edge cases: empty list or list with one node */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Traverse the list starting from the second node */
	for (current = (*list)->next; current != NULL; current = current->next)
	{
		/* Set up a pointer to traverse the sorted part of the list */
		traverse = current->prev;

		/*Move elements of the sorted part of the list that are greater than*/
		/*the current nodeto one position ahead of their current position.	*/
		while (traverse != NULL && traverse->n > current->n)
		{
			/* Swap nodes */
			if (traverse->prev != NULL)
				traverse->prev->next = current;
			else
				*list = current;

			current->prev = traverse->prev;
			traverse->prev = current;
			traverse->next = current->next;

			if (current->next != NULL)
				current->next->prev = traverse;

			current->next = traverse;

			traverse = current->prev;

			/* Print the list after each swap */
			print_list(*list);
		}
	}
}
