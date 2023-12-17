#include "sort.h"

/**
 * partition - The array partition
 * @array: array to the sort
 * @first: the first position
 * @last: the last position
 * @size: the array size
 * Return: interger pivot index
 */
int partition(int *array, int first, int last, size_t size)
{
	int a = first - 1, aux, x;

	for (x = first; x <= last - 1; x++)
	{
		if (array[x] < array[last])
		{
			a++;
			if (a < x)
			{
				aux = array[a];
				array[a] = array[x];
				array[x] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[a + 1] > array[last])
	{
		aux = array[a + 1];
		array[a + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (a + 1);
}

/**
 * qs - sorts an array of the integers recursively
 * @array: array to the sort
 * @first: the first position
 * @last: the last position
 * @size: the array size
 */
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of the integer using the Quick
 * sort algorithm in ascending order.
 * @array: array to the sort.
 * @size: the array size.
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
