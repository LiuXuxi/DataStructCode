#include"heapsort.h"

void MiniHeapSort(SortTable* table) {
	miniHeap mini_heap(table->length);
	for (int i = 0; i < table->length; ++i) {
		mini_heap.insert(table->data[i].key);
	}
	for (int i = 0; i < table->length; ++i) {
		table->data[i].key = mini_heap.extract();
	}
}