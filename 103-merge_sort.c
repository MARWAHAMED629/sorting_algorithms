#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_left_right - print the left and right partitions
 * @array: an array
 * @size: size of the second array
 * @first: initial the position
 * @mid: middle the position
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int b;

	printf("Merging...\n");
	printf("[left]: ");
	b = first;
	while (b < mid)
	{
		if (b != mid - 1)
			printf("%d, ", array[b]);
		else
			printf("%d\n", array[b]);
		b++;
	}

	printf("[right]: ");
	b = mid;
	while (b < size)
	{
		if (b < size - 1)
			printf("%d, ", array[b]);
		else
			printf("%d\n", array[b]);
		b++;
	}
}

/**
 * merge - merge a values in the position of the array
 * @array: the first array
 * @size: size of the second array
 * @cpy: copy of an array
 * @first: initial position
 * @mid: middle position
 * first one of the second array
 */
void merge(int *array, int size, int first, int mid, int *cpy)
{
	int a, b, x;

	print_left_right(array, size, first, mid);

	a = first;
	b = mid;

	printf("[Done]: ");
	x = first;
	while (x < size)
	{
		if (a < mid && (b >= size || array[a] <= array[b]))
		{
			cpy[x] = array[a];
			a++;
		}
		else
		{
			cpy[x] = array[b];
			b++;
		}
		if (x < size - 1)
			printf("%d, ", cpy[x]);
		else
			printf("%d\n", cpy[x]);
		x++;
	}
}
/**
 * mergeSort - the array separator
 * @cpy: copy of an array
 * @first: initial position
 * @size: size of the original  array
 * @array: the original array
 */
void mergeSort(int *cpy, int first, int size, int *array)
{
	int m;

	if (size - first < 2)
		return;

	m = (size + first) / 2;

	mergeSort(array, first, m, cpy);
	mergeSort(array, m, size, cpy);

	merge(cpy, size, first, m, array);
}
/**
 * copy_array - copy the array of integer.
 * @arr: array src
 * @cpy: array dest
 * @size : array size
 */
void copy_array(int *arr, int *cpy, int size)
{
	int a;

	for (a = 0; a < (int)size; a++)
		cpy[a] = arr[a];
}

/**
 * merge_sort - create the partition and copy
 * @array: the array
 * @size : an array size
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	copy = malloc(sizeof(int) * size - 1);

	if (copy == NULL)
		return;

	copy_array(array, copy, size);

	mergeSort(copy, 0, size, array);
	free(copy);
}
