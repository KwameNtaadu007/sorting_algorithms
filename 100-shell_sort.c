#include "sort.h"

/**
 * shell_sort - A function that sorts an array of integers
 * in ascending order using the Shell sort algorithm
 *
 * @array: The arrray to be sorted
 * @size: the size of the array
 * Return: no return
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	/* Calculating the initial gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = tmp;
		}

		/* Print the array after each pass */
		print_array(array, size);

		/* Update the gap for the next pass */
		gap = (gap - 1) / 3;
	}
}
