#pragma once

class stack {
private:
	int* arr;
	int top;
	int size;
public:
	stack(int _size = 100) {
		size = _size;
		arr = new int[size];
		top = -1;
	}
	void push(const int& value) {
		if (top == size - 1) {
			std::cout << "Stack Overflow!\n";
			return;
	}
		arr[++top] = value;
	}

	int  topValue() {
		if (empty()) {
			std::cout << "Stack is Empty...\n";
			return -1;
	}
		return arr[top];
	}

	int sizeofStack() {
		return top + 1;
	}
	bool empty() {
		if (top < 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void pop() {
		if (empty()) {
			std::cout << "Stack underflow!\n";
			return;
	}
		--top;
	}
	void display()
	{
		if (empty()) {
			std::cout << "Stack is Empty...\n";
			return ;
		}

		std::cout << "\n The Values in Stack (Top to Bottom)";
		for (int i = top; i >=0; i--) {
			std::cout << "\n  " << arr[i] ;
		}
	}
		~stack() {
		delete[] arr;

	}

};