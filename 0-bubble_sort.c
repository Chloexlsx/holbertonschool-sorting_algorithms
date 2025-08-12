#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using Bubble sort
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Description: Prints the array after each swap using print_array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (n = size; n > 1; n--)
	{
		swapped = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
