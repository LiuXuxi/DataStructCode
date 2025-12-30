#include"miniheap.h"

void miniHeap::shiftup(int index) {
	while (index > 1 && data[index / 2] > data[index]) {
		keyType temp = data[index];
		data[index] = data[index / 2];
		data[index / 2] = temp;
		index /= 2;
	}
}

void miniHeap::shiftdown(int index) {
	while (index * 2 <= len) {
		int k = index * 2;
		if (k + 1 <= len && data[k + 1] < data[k])k = k + 1;
		if (data[index]<=data[k])return;
		keyType temp = data[k];
		data[k] = data[index];
		data[index] = temp;
		index = k;
	}
}

miniHeap::miniHeap(int n)
	:len(0), capacity(n) {
	data = new keyType[n + 1];
	std::memset(data, 0, sizeof(keyType) * capacity);
}

miniHeap::~miniHeap() {
	if (data) {
		delete[]data;
		data = nullptr;
	}
}

void miniHeap::insert(keyType v) {
	if (len >= capacity) {
		std::cout << "minheap is full" << std::endl;
		return;
	}
	data[++len] = v;
	shiftup(len);
}

bool miniHeap::isEmpty() const {
	return len == 0;
}

int miniHeap::size() const {
	return len;
}

keyType miniHeap::extract() {
	int result = data[1];
	data[1] = data[len--];
	shiftdown(1);
	return result;
}