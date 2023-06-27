#include "sort.h"

void mysort(int *a, int size, int n);

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
	size_t target = 1;

	while (target < size)
		target = (target * 3) + 1;

	while ((target = (target - 1) / 3) > 0)
		mysort(array, size, target);
}

/**
 * mysort - The auxi function for shell_sort function
 * @a: the input arrray
 * @size: the size of the array
 * @n: intervale
 * Return: no return
 */

void mysort(int *a, int size, int n)
{
	int temp, i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				temp = a[j];
				a[j] = a[j - n];
				a[j - n] = temp;
			}
		}
	}
	print_array(a, size);
}
