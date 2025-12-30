#include "miniheap.h"
#include "heapsort.h"
#include "../sortHelper.h"
#include <iostream>
#include <vector>

// 测试 MiniHeap 类的基本功能
void test01() {
    std::vector<int> data = { 9, 3, 7, 6, 5, 1, 10 };
    miniHeap mini_heap(data.size());

    for (int item : data) {
        mini_heap.insert(item);
    }

    std::cout << "Extracted elements from heap: ";
    while (!mini_heap.isEmpty()) {
        std::cout << mini_heap.extract() << " ";
    }
    std::cout << std::endl;
}

void test02() {
    int n = 100000;
    SortTable* table = generateRandomArray(n, 0, n + 1000);
    testSort("HeapSort: ", MiniHeapSort, table);
    releaseSortTable(table);
}

int main() {
    std::cout << "--- Test 1: Basic Heap Operations ---" << std::endl;
    test01();
    std::cout << "\n--- Test 2: Heap Sort Performance ---" << std::endl;
    test02();

    return 0;
}