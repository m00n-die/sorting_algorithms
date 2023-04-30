#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 *
 * @b: The second integer to swap.
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, j;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				swap_ints(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
