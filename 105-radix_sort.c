#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: an array of integers.
 * @size: the size of the array.
 *
 * Return: the maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int m, a;

	for (m = array[0], a = 1; a < size; a++)
	{
		if (array[a] > m)
			m = array[a];
	}

	return (m);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array:an array of integers.
 * @size: the size of the array.
 * @sig: the significant digit to sort on.
 * @buff: a buffer to the store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t c;

	for (c = 0; c < size; c++)
		count[(array[c] / sig) % 10] += 1;

	for (c = 0; c < 10; c++)
		count[c] += count[c - 1];

	for (c = size - 1; (int)c >= 0; c--)
	{
		buff[count[(array[c] / sig) % 10] - 1] = array[c];
		count[(array[c] / sig) % 10] -= 1;
	}

	for (c = 0; c < size; c++)
		array[c] = buff[c];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: an array of integers.
 * @size: the size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, s, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	max = get_max(array, size);
	for (s = 1; max / s > 0; s *= 10)
	{
		radix_counting_sort(array, size, s, buf);
		print_array(array, size);
	}

	free(buf);
}
