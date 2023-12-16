#include "sort.h"

/**
 * selection_sort - sort the list by selection_sort
 * @array: The array to be printed.
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t z, b, less, tmp, swap;

	if (array == NULL)
		return;
	for (z = 0; z < size; z++)
	{
		for (less = z, b = z; b < size; b++)
			if (array[b] < array[less])
			{
				less = b;
				swap = 1;
			}
		if (swap == 1)
		{
			tmp = array[less];
			array[less] = array[z];
			array[z] = tmp;
			print_array(array, size);
			swap = 0;
		}
	}
}
