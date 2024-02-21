#include "sort.h"

void merge_subarr(int *subarr, int *_buffer, size_t front, size_t mid,
		size_t back);
void merge_sort_recursion(int *subarr, int *_buffer, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers_.
 * @subarr: A subarray of an array of integers_ to sort.
 * @_buffer: A _buffer to store the _sorted subarray.
 * @front: The front indx of the array.
 * @mid: The middle indx of the array.
 * @back: The back indx of the array.
 */
void merge_subarr(int *subarr, int *_buffer, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		_buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		_buffer[k++] = subarr[i];
	for (; j < back; j++)
		_buffer[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = _buffer[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursion - Implement the merge sort algorthmthrough recursion.
 * @subarr: A subarray of an array of integers_ to sort.
 * @_buffer: A _buffer to store the _sorted result.
 * @front: The front indx of the subarray.
 * @back: The back indx of the subarray.
 */
void merge_sort_recursion(int *subarr, int *_buffer, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursion(subarr, _buffer, front, mid);
		merge_sort_recursion(subarr, _buffer, mid, back);
		merge_subarr(subarr, _buffer, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers_ in ascendn
 *              order using the merge sort algorthm
 * @array: An array of integers_.
 * @size: The size of the array.
 *
 * Description: Implements the top-DOWN merge sort algorthm
 */
void merge_sort(int *array, size_t size)
{
	int *_buffer;

	if (array == NULL || size < 2)
		return;

	_buffer = malloc(sizeof(int) * size);
	if (_buffer == NULL)
		return;

	merge_sort_recursion(array, _buffer, 0, size);

	free(_buffer);
}
