#include "sort.h"

/**
 * counting_sort - Sort an array of integrs in ascendn order
 *                 using the counting sort algorthm
 * @array: An array of integrs.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it UPWARD.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *_sorted, max, i;

	if (array == NULL || size < 2)
		return;

	_sorted = malloc(sizeof(int) * size);
	if (_sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(_sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		_sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = _sorted[i];

	free(_sorted);
	free(count);
}

/**
 * get_max - Get the maximum val in an array of integrs.
 * @array: An array of integrs.
 * @size: The size of the array.
 *
 * Return: The maximum integr in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

