/*
This file contains the declaration for the heapSort function used to implement
the heap-sort algorithm.

Time complexity for the heap sort algorithm is O(nlogn)
*/

#include "HeapSort.hpp"
#include "MinHeap.hpp"

void heapSort(int* array, int size) {
	// Build heap in O(n) time
	MinHeap heap = MinHeap(array, size);

	// Sort in O(logn) time
	for(int i = 0; i < size; i ++ ) {
		array[i] = heap.deleteMin();
	}
}