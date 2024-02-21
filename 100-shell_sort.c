#include "sort.h"

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
 * shell_sort - Sort an array of integrs in ascendn
 *              order using the shell sort algorthm
 * @array: An array of integrs.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t count, i, j;

	if (array == NULL || size < 2)
		return;

	for (count = 1; count < (size / 3);)
		count = count * 3 + 1;

	for (; count >= 1; count /= 3)
	{
		for (i = count; i < size; i++)
		{
			j = i;
			while (j >= count && array[j - count] > array[j])
			{
				swap_ints(array + j, array + (j - count));
				j -= count;
			}
		}
		print_array(array, size);
	}
}
