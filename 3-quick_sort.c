#include "sort.h"

void exchange_ints(int *first, int *second);
int l_partition(int *array, size_t size, int left, int right);
void l_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * l_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pvt).
 * @ints_arr: The array of integers.
 * @asize: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int l_partition(int *ints_arr, size_t asize, int left, int right)
{
	int *pvt, over, under;

	pvt = ints_arr + right;
	for (over = under = left; under < right; under++)
	{
		if (ints_arr[under] < *pvt)
		{
			if (over < under)
			{
				exchange_ints(ints_arr + under, ints_arr + over);
				print_array(ints_arr, asize);
			}
			over++;
		}
	}

	if (ints_arr[over] > *pvt)
	{
		exchange_ints(ints_arr + over, pvt);
		print_array(ints_arr, asize);
	}

	return (over);
}

/**
 * l_sort - Implement the quicksort algorithm through recursion.
 * @ints_arr: An array of integers to sort.
 * @asize: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void l_sort(int *ints_arr, size_t asize, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = l_partition(ints_arr, asize, left, right);
		l_sort(ints_arr, asize, left, part - 1);
		l_sort(ints_arr, asize, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @ints_arr: An array of integers.
 * @asize: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *ints_arr, size_t asize)
{
	if (ints_arr == NULL || asize < 2)
		return;

	l_sort(ints_arr, asize, 0, asize - 1);
}
