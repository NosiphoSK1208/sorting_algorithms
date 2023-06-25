#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list  of integers
 *
 * @a_list: \List to be printed
 */
void print_list(const listint_t *a_list)
{
	int x;

	x = 0;
	while (a_list)
	{
		if (x > 0)
			printf(", ");
		printf("%d", a_list->n);
		++x;
		a_list = a_list->next;
	}
	printf("\n");
}
