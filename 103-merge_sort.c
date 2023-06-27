#include "sort.h"
#include <stdio.h>

void print_data(char *msg, int *a, int from, int to);
void merge(int *a, int low, int middle, int high, int *buff);
void msort(int *array, int low, int high, int *buffer);

/**
 * print_data - prints data
 * @msg: message
 * @a: array
 * @from: from
 * @to: to
 * Return: no return
 */

void print_data(char *msg, int *a, int from, int to)
{
	char *abc;
	int i;

	printf("[%s]: ", msg);
	abc = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", abc, a[i]);
		abc = ", ";
	}
	printf("\n");
}

/**
 * merge - The Aux function for Merge sort algorithm
 * @a: array
 * @low: low index
 * @middle: middle
 * @high: high index
 * @buff: buffer
 * Return: no return
 */

void merge(int *a, int low, int middle, int high, int *buff)
{
	int mid, lm, i;

	mid = i = low;
	lm = middle + 1;

	printf("Merging...\n");
	print_data("left", a, low, middle);
	print_data("right", a, middle + 1, high);

	while (mid <= middle && lm <= high)
	{
		if (a[mid] < a[lm])
			buff[i++] = a[mid++];
		else
			buff[i++] = a[lm++];
	}

	while (mid <= middle)
		buff[i++] = a[mid++];

	while (lm <= high)
		buff[i++] = a[lm++];

	for (i = low; i <= high; i++)
		a[i] = buff[i];

	print_data("Done", a, low, high);
}

/**
 * msort -The Aux function for Merge sort algorithm
 * @array: array
 * @low: low index
 * @high: high index
 * @buffer: buffer
 * Return: no return
 */

void msort(int *array, int low, int high, int *buffer)
{
	int mid;

	if (low < high)
	{
		mid = (low + high - 1) / 2;
		msort(array, low, mid, buffer);
		msort(array, mid + 1, high, buffer);
		merge(array, low, mid, high, buffer);
	}
}

/**
 * merge_sort -Sorts an array of integers in ascending order
 * @array: The array
 * @size: size of array
 * Return: no return
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	msort(array, 0, size - 1, buffer);
	free(buffer);
}

