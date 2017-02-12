#include "min_heap.h"
#include <assert.h>
#include <math.h>

#define LEFT(i) ((i<<1)+1)
#define RIGHT(i) ((i<<1)+2)
#define PARENT(i) ((i-1)>>1)
#define FIRST_LEAF(n) (n>>1)


void min_heapify(int heap[], int heap_size, int postion)
{
	int l, r, min, tmp;

	l = LEFT(postion);
	r = RIGHT(postion);
	if(l < heap_size && heap[l] < heap[postion])
	{
		min = l;
	}
	else
		min = postion;
	if(r < heap_size && heap[r] < heap[min])
		min = r;

	if(min != postion)
	{
		tmp = heap[min];
		heap[min] = heap[postion];
		heap[postion] = tmp;
		min_heapify(heap, heap_size, min);
	}
}

void build_min_heap(int a[], int a_size)
{
	int i;
	
	for(i = FIRST_LEAF(a_size) - 1; i >= 0; i--)
		min_heapify(a, a_size, i);
}


//result:desc-array
void heap_sort(int a[], int a_size)
{
	int tmp, p = a_size - 1;

	build_min_heap(a, a_size);

	while(p >= 1)
	{
		tmp = a[p];
		a[p] = a[0];
		a[0] = tmp;
		p = p - 1;
		min_heapify(a, p + 1, 0);
	}
}

int heap_minimum(int heap[])
{
	return heap[0];
}

int extract_heap_minimun(int heap[], int *heap_size)
{
	int ret;
	assert(heap_size >= 0);

	ret = heap[0];
	heap[0] = heap[*heap_size - 1];
	*heap_size = *heap_size - 1;
	min_heapify(heap, *heap_size, 0);

	return ret;
}

void min_heap_decrease_key(int heap[], int heap_size, int postion, int value)
{
	
	while(postion > 0 && value < heap[PARENT(postion)] )
	{
		heap[postion] = heap[PARENT(postion)];
		postion = PARENT(postion);
	}
	heap[postion] = value;
}

void min_heap_insert(int heap[], int *heap_size, int heap_length, int value)
{
	 assert(*heap_size < heap_length);


	 heap[*heap_size] = (int) HUGE_VAL;
	 *heap_size += 1;
	 min_heap_decrease_key(heap, *heap_size, *heap_size - 1, value);
}

