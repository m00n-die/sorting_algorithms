#include <stdio.h>
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
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * 
 * @array: array to be sorted
 * 
 * @size: size of the array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int *min_val;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_val = array + i;
		for (j = i + 1; j < size; j++)
			min_val = (array[j] < *min_val) ? (array + j) : min_val;

		if ((array + i) != min_val)
		{
			swap(array + i, min_val);
			print_array(array, size);
		}
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}