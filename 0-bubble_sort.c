#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Description: Swaps the values of the two
 * integers pointed to by @a and @b.
 */
void swap_ints(int *a, int *b)
{
	/* Swap the values of the two integers */
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Sorts the array of integers in ascending order
 * using the bubble sort algorithm.
 */
void bubble_sort(int *array, size_t size)
{
	/* Initialize variables */
	size_t i, len = size;
	bool swapped = true;

	/* Loop through the array */
	while (swapped)
	{
		swapped = false;

		/* For each element in the array */
		for (i = 0; i < len - 1; i++)
		{
			/* If the current element is greater than the next element */
			if (array[i] > array[i + 1])
			{
				/* Swap the two elements */
				swap_ints(array + i, array + i + 1);
				swapped = true;
			}
		}

		/* Decrement the length of the array */
		len--;
	}
}
