#include "sort.h"

/**
 * bubble_sort - sort the  list with bubble
 * @array: an array to be printed
 * @size: Number of the elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = 0, a = size;
	int hold;

	if (array == NULL)
		return;
	for (a = size; a > 0; a--)
	{
		for (n = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				hold = array[n];
				array[n] = array[n + 1];
				array[n + 1] = hold;
				print_array(array, size);
			}
		}
	}
}
