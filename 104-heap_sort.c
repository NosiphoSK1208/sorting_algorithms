#include "sort.h"

void exchange_ints(int *first, int *second);
void greatest_heap(int *arr_int, size_t asize, size_t min, size_t aroot);
void heap_sort(int *arr_int, size_t asize);

/**
 * exchange_ints - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void exchange_ints(int *first, int *second)
{
	int impermanent;

	impermanent = *first;
	*first = *second;
	*second = impermanent;
}

/**
 * greatest_heap - Turn a binary tree into a complete binary heap.
 * @arr_int: an array of integers representing a binary tree.
 * @asize: Size of the array/tree.
 * @min: The index of the min row of the tree.
 * @aroot: The root node of the binary tree.
 */
void greatest_heap(int *arr_int, size_t asize, size_t min, size_t aroot)
{
	size_t s_left, s_right, s_large;

	s_left = 2 * aroot + 1;
	s_right = 2 * aroot + 2;
	s_large = aroot;

	if (s_left < min && arr_int[s_left] > arr_int[s_large])
		s_large = s_left;
	if (s_right < min && arr_int[s_right] > arr_int[s_large])
		s_large = s_right;

	if (s_large != aroot)
	{
		exchange_ints(arr_int + aroot, arr_int + s_large);
		print_array(arr_int, asize);
		greatest_heap(arr_int, asize, min, s_large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @arr_int: an array of integers.
 * @asize: Size of the array.
 *
 * Description: Implements the sift-DESCENDING heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *arr_int, size_t asize)
{
	int k;

	if (arr_int == NULL || asize < 2)
		return;

	for (k = (asize / 2) - 1; k >= 0; k--)
		greatest_heap(arr_int, asize, asize, k);

	for (k = asize - 1; k > 0; k--)
	{
		exchange_ints(arr_int, arr_int + k);
		print_array(arr_int, asize);
		greatest_heap(arr_int, asize, k, 0);
	}
}
