#include "sort.h"

/**
 * get_greatest  - Get the limit value in an array of integers.
 * @arr: An array of integers.
 * @asize: Size of the arr.
 *
 * Return: The maximum integer in the arr.
 */
int get_greatest(int *arr, int asize)
{
	int limit, k;

	for (limit = arr[0], k = 1; k < asize; k++)
	{
		if (arr[k] > limit)
			limit = arr[k];
	}

	return (limit);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @arr:Array of integers.
 * @asize: Size of the arr.
 *
 * Description: Prints the counting arr after setting it ASCENDING.
 */
void counting_sort(int *arr, size_t asize)
{
	int *cast_up, *resolved, limit, k;

	if (arr == NULL || asize < 2)
		return;

	resolved = malloc(sizeof(int) * asize);
	if (resolved == NULL)
		return;
	limit = get_greatest(arr, asize);
	cast_up = malloc(sizeof(int) * (limit + 1));
	if (cast_up == NULL)
	{
		free(resolved);
		return;
	}

	for (k = 0; k < (limit + 1); k++)
		cast_up[k] = 0;
	for (k = 0; k < (int)asize; k++)
		cast_up[arr[k]] += 1;
	for (k = 0; k < (limit + 1); k++)
		cast_up[k] += cast_up[k - 1];
	print_array(cast_up, limit + 1);

	for (k = 0; k < (int)asize; k++)
	{
		resolved[cast_up[arr[k]] - 1] = arr[k];
		cast_up[arr[k]] -= 1;
	}

	for (k = 0; k < (int)asize; k++)
		arr[k] = resolved[k];

	free(resolved);
	free(cast_up);
}
