#include "sort.h"

/**
 * selection_sort - This sort array of integers in ascending order
 * @array: The array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, _min_idx;

	for (i = 0; i < size - 1; i++)
	{
		_min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[_min_idx])
				_min_idx = j;
		}
		if (_min_idx != i)
		{
			int temp = array[i];

			array[i] = array[_min_idx];
			array[_min_idx] = temp;
			print_array(array, size);
		}
	}
}
