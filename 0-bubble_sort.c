#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Bubble sort algorithm 
 * @array: array to be sorted
 * @size: size of array
 * 
 * Return: 0 (Success)
 */

void bubble_sort(int *array, size_t size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int swaps = 0;
        for (int i = 0; i < size - step - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                print_array(array, size);
                
                swaps = 1;
            }
        }
        if (swaps == 0) 
            break;
    }
}
