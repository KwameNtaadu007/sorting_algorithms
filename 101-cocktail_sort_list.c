#include "sort.h"

void sort_list(listint_t **list);
void dec_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void inc_sort(listint_t **ptr, listint_t **limit, listint_t **list);

/**
 * swap_list - swaps the elements of the list
 *
 * @ptr1: first pointer
 * @ptr2: second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 * Return: no return
 */

void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *new, *temp;

	new = *ptr1;
	temp = *ptr2;

	new->next = temp->next;
	temp->prev = new->prev;

	if (temp->next)
		temp->next->prev = new;

	if (new->prev)
		new->prev->next = temp;

	new->prev = temp;
	temp->next = new;

	if (n == 0)
		*ptr1 = temp;
	else
		*ptr2 = new;
}

/**
 * inc_sort - moves bigger numbers to the end
 *
 * @ptr: the pointer to the bigger number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */

void inc_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *new;

	new = *ptr;

	while (new != *limit && new->next != *limit)
	{
		if (new->n > new->next->n)
		{
			swap_list(&new, &(new->next), 0);
			if (new->prev == NULL)
				*list = new;
			print_list(*list);
		}
		new = new->next;
	}

	*limit = new;
	*ptr = new;
}

/**
 * dec_sort - moves smaller numbers to the start
 *
 * @ptr: pointer to the smaller number
 * @limit: limit of the list
 * @list: list of integers
 * Return: no return
 */

void dec_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *new;

	new = *ptr;

	while (new != *limit && new->prev != *limit)
	{
		if (new->n < new->prev->n)
		{
			swap_list(&(new->prev), &new, 1);
			if (new->prev->prev == NULL)
				*list = new->prev;
			print_list(*list);
		}
		new = new->prev;
	}

	*limit = new;
	*ptr = new;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order
 *
 * @list: head of the linked list
 * Return: no return
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *limit, *limit_1, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit = limit_1 = NULL;
	ptr = *list;

	do {
		inc_sort(&ptr, &limit, list);
		dec_sort(&ptr, &limit_1, list);
	} while (limit != limit_1);
}

