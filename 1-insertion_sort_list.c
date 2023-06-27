#include "sort.h"

void insertion_sort_list(listint_t **list) {
	listint_t *current = *list;
	listint_t *next = NULL;

	while (current != NULL) {
		next = current->next;

		/* Find the right place to insert current */
		while (next != NULL && current->n > next->n) {
			/* Swap current and next*/
			current->next = next->next;
			next->next = current;
			current = next;
			next = current->next;
		}

		/* Print the list*/
		print_list(*list);
	}
}

