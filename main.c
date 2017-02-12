#include "min_heap.h"
#include <stdio.h>


int main()
{
	int size = 12;
	int a[] = {4, 8, 19, 20, 0, 3, 6, 9, 7, 10, 15, 12};
	int ret;

	build_min_heap(a, size);

	printf("heap[0]: %i\n", heap_minimum(a));

	printf("minimum: %i\n ", extract_heap_minimun(a, &size));
	printf("size: %i\n", size);

	min_heap_insert(a, &size, 15, 5);

	printf("heap[-1]: %i\n", a[11]); //12
	printf("size: %i\n", size);

	heap_sort(a, size);

	ret = 5;
}