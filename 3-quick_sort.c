#include "sort.h"

/**
 * partition - Takes the last element of the array as pivot, places
 *             the pivot element at its correct position in sorted
 *             array, and places all smaller (smaller than pivot)
 *             to left of pivot and all greater elements to right of pivot
 * @array: array to sort
 * @low: lower index
 * @high: higher index
 * @size: size of the array
 * Return: index of pivot element
 **/
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * q_sort - recursive implementation of quicksort
 * @array: array to sort
 * @low: lower index
 * @high: higher index
 * @size: size of the array
 **/
void q_sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		q_sort(array, low, pi - 1, size);
		q_sort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 *              the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 **/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
