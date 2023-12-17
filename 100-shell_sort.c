#include "sort.h"

/**
 * shell_sort - Shell sort - the Knuth Sequence
 * @array: array to the sort
 * @size: the size of an array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, a, x, tmp;

	while (gap < ((int)(size)))
		gap = (3 * gap) + 1;
	for (gap = (gap - 1) / 3; gap > 0; gap = (gap - 1) / 3)
	{
		for (a = gap; a < (int)size; a += 1)
		{
			tmp = array[a];

			for (x = a; x >= gap && array[x - gap] > tmp; x -= gap)
				array[x] = array[x - gap];

			array[x] = tmp;
		}
		print_array(array, size);
	}
}
