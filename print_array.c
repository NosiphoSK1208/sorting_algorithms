#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @arr_pr: Array to be printed
 * @asize: Total of elements in array
 */
void print_array(const int *arr_pr, size_t asize)
{
	size_t k;

	k = 0;
	while (arr_pr && k < asize)
	{
		if (k > 0)
			printf(", ");
		printf("%d", arr_pr[k]);
		++k;
	}
	printf("\n");
}
