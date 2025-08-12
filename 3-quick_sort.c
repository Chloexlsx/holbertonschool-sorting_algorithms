#include "sort.h"

/**
 * swap_ints - swap two ints
 * @a: int a
 * @b: int b
 *
 * Return: void;
 */
static void swap_ints(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}
/**
 * lomuto_partition - pivot = array[high]
 * @array: array
 * @low: int low
 * @high: int high
 * @size: size of the array
 *
 * Return: int;
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_rec - sort
 * @array: array
 * @low: int low
 * @high: int high
 * @size: size of the array
 *
 * Return: void;
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = lomuto_partition(array, low, high, size);

		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of ints in ascending order (Lomuto)
 * @array: array of ints
 * @size: array length
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_rec(array, 0, (int)size - 1, size);
}
