#include "sort.h"

void swap_ints(int *i, int *x);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @i: the first integer to swap.
 * @x: the second integer to swap.
 */
void swap_ints(int *i, int *x)
{
	int temp;

	temp = *i;
	*i = *x;
	*x = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: an array of integers.
 * @size: the size of the array.
 * @start: the starting index of the sequence in array to sort.
 * @seq: the size of the sequence to sort.
 * @flow: the direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t a, jump = seq / 2;

	if (seq > 1)
	{
		for (a = start; a < start + jump; a++)
		{
			if ((flow == UP && array[a] > array[a + jump]) ||
			    (flow == DOWN && array[a] < array[a + jump]))
				swap_ints(array + a, array + a + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: an array of the integers.
 * @size: the size of the array.
 * @start: the starting index of a block of the building bitonic sequence.
 * @seq: the size of a block of the building bitonic sequence.
 * @flow: the direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t c = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, c, UP);
		bitonic_seq(array, size, start + c, c, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
