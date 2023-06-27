#include "sort.h"

void _qsort(int *a, int low, int high, int size);

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_qsort(array, 0, size - 1, size);
}

/**
 * _qsort - Sorts a subset of an array of integers in ascending order
 *          using the quicksort algorithm.
 * @a: The array of integers.
 * @low: The starting index of the subset to sort.
 * @high: The ending index of the subset to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap of two elements.
 */
void _qsort(int *a, int low, int high, int size)
{
	int p, w, i, tmp;

	if (low < high)
	{
		p = high;
		w = low;
		for (i = low; i < high; i++)
		{
			if (a[i] < a[p])
			{
				if (i != w)
				{
					tmp = a[i];
					a[i] = a[w];
					a[w] = tmp;
					print_array(a, size);
				}
				w++;
			}
		}
		if (w != p && a[w] != a[p])
		{
			tmp = a[w];
			a[w] = a[p];
			a[p] = tmp;
			print_array(a, size);
		}
		_qsort(a, low, w - 1, size);
		_qsort(a, w + 1, high, size);
	}
}

