#include "sort.h"
#include <stdlib.h>

/**
 * arr_max - the array max
 * @array: the array
 * @size: size of an array
 * Return: max
 */
int arr_max(int *array, size_t size)
{
	int m;
	size_t a;

	m = array[0];
	for (a = 1; a < size; a++)
		if (array[a] > m)
			m = array[a];
	return (m);
}

/**
 * counting_sort - sorts an array with the Counting sort algorithm
 * @array: the array to sort
 * @size: size of an array
 */
void counting_sort(int *array, size_t size)
{
	int *arr, *o_arr, m, num;
	size_t a;

	if (size < 2 || !array)
		return;
	m = arr_max(array, size);

	arr = malloc(sizeof(size_t) * (m + 1));
	o_arr = malloc(sizeof(int) * size);

	for (a = 0; (int)a <= m; a++)
		arr[a] = 0;
	for (a = 0; a < size; a++)
	{
		num = array[a];
		arr[num] += 1;
	}
	for (a = 1; (int)a <= m; a++)
		arr[a] += arr[a - 1];
	print_array(arr, m + 1);
	for (a = 0; a < size; a++)
	{
		o_arr[arr[array[a]] - 1] = array[a];
		arr[array[a]]--;
	}
	for (a = 0; a < size; a++)
		array[a] = o_arr[a];

	free(o_arr);
	free(arr);
}
