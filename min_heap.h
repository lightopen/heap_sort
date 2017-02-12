/*
	min-heap
*/
#pragma once
#ifndef MIN_HEAP_H__
#define MIN_HEAP_H__

void min_heapify(int heap[], int heap_size, int postion);

void build_min_heap(int a[], int a_size);

void heap_sort(int a[], int a_size);

int heap_minimum(int heap[]);

int extract_heap_minimun(int heap[], int *heap_size);

void min_heap_decrease_key(int heap[], int heap_size, int postion, int value);

void min_heap_insert(int heap[], int *heap_size, int heap_length, int value);



#endif //MIN_HEAP_H__