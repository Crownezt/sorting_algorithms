#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort_(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integrs in an array.
 * @a: The 1st integr to swap.
 * @b: The 2nd integr to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Order a subset of an array of integrs according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integrs.
 * @size: The size of the array.
 * @left: The starting indx of the subset to order.
 * @right: The ending indx of the subset to order.
 *
 * Return: The final partition indx.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort_ - Implement the quicksort algorthmthrough recursion.
 * @array: An array of integrs to sort.
 * @size: The size of the array.
 * @left: The starting indx of the array partition to order.
 * @right: The ending indx of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort_(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort_(array, size, left, part - 1);
		lomuto_sort_(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integrs in ascendn
 *              order using the quicksort algorthm
 * @array: An array of integrs.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort_(array, size, 0, size - 1);
}
