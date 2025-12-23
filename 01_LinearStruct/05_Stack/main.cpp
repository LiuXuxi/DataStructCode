#include"stack.h"

void arrayStackTest() {
	arrayStack<int>stack(5);
	if (stack.isEmpty()) {
		for (int i = 0; i < 5; i++)stack.push(i * 10);
	}
	std::cout << stack.isFull() << std::endl;
	int e;
	stack.pop(e);
	std::cout << e << std::endl;
	while (!stack.isEmpty()) {
		stack.pop(e);
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void linkStackTest() {
	linkStack<int>stack;
	if (stack.isEmpty()) {
		for (int i = 0; i < 5; i++)stack.push(i * 10);
	}
	std::cout << stack.getNum() << std::endl;
	int e;
	stack.getTop(e);
	std::cout << e << std::endl;
	while (!stack.isEmpty()) {
		stack.getTop(e);
		std::cout << e << " ";
		stack.pop();
	}
	std::cout << std::endl;
	std::cout << stack.getNum() << std::endl;
}

int main() {
	//arrayStackTest();
	linkStackTest();
	return 0;
}