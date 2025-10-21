#pragma once
template<typename T>
class stack {

private:
	int *arr;
	int _top;
	int _size;
public:
	stack(int size = 100) {
		_size = size;
		arr = new int[_size];
		_top = -1;
	}
	// Comparison Friend Function Prototype
	template<typename T>
	friend bool operator==(const stack<T>  &, const stack<T>  & ); // Equal to Operator
	template<typename T>
	friend bool operator<(const stack<T>  &, const stack<T>  &); // Less Than Operator
	template<typename T>
	friend bool operator>(const stack<T>  &, const stack<T>  &); // Greater Than Operator
	template<typename T>
	friend bool operator<=(const stack<T>  &, const stack<T>  &); // Less Than or Equal to Operator
	template<typename T>
	friend bool operator>=(const stack<T>  &, const stack<T>  &); // Greater Than or Equal to Operator
	//-------------------------------------
	void push(const int &Value) {
		arr[++_top] = Value;
	}
	int top() {
		return arr[_top];
	}

	int size() {
		return _top + 1;
	}
	bool empty() {
		if (_top < 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void pop() {
		--_top;
	}

	void swap(stack &other_stack) {
		std::swap(_top, other_stack._top);
		std::swap(_size, other_stack._size);
		std::swap(arr, other_stack.arr);
	}
	// Deallocating the Dynamic Memory of Array!
	~stack() {
		delete []arr;
	}
};

// Stack Comparision NonMember Functions....

// Comparision with Equal to Operator
template<typename T>
bool operator==(const stack<T>  &Stack1, const stack<T>  &Stack2 ){
	int size1 = Stack1._size;
	int size2 = Stack2._size;
	int final_size;
	if (Stack1._size < Stack2._size) {
		final_size = Stack1._size;
	}else { final_size = Stack2._size; }
	
	for (int i = 0;i < final_size;++i)
	{
		
		if (Stack1.arr[i] != Stack2.arr[i]) {
			return false;
		}
	
	}
	return true;
}

//  Comparision with Less than Operator
template<typename T>
bool operator<(const stack<T>  &Stack1, const stack<T>  &Stack2) {
	int size1 = Stack1._size;
	int size2 = Stack2._size;
	int final_size;
	if (Stack1._size < Stack2._size) {
		final_size = Stack1._size;
	}
	else { final_size = Stack2._size; }

	for (int i = 0;i < final_size;++i)
	{

		if (Stack1.arr[i] < Stack2.arr[i]) {
			return true;
		}
		else if (Stack1.arr[i] > Stack2.arr[i])
			return false;
	}
	return Stack1 < Stack2;
}

//  Comparision with Greater than Operator
template<typename T>
bool operator>(const stack<T>  &Stack1, const stack<T>  &Stack2) {
	int size1 = Stack1._size;
	int size2 = Stack2._size;
	int final_size;
	if (Stack1._size < Stack2._size) {
		final_size = Stack1._size;
	}
	else { final_size = Stack2._size; }

	for (int i = 0;i < final_size;++i)
	{

		if (Stack1.arr[i] > Stack2.arr[i]) {
			return true;
		}
		else if (Stack1.arr[i] < Stack2.arr[i])
			return false;
	}
	return Stack1 > Stack2;
}

//  Comparision with Less than or Equal to Operator
template<typename T>
bool operator<=(const stack<T>  &Stack1, const stack<T>  &Stack2) {
	int size1 = Stack1._size;
	int size2 = Stack2._size;
	int final_size;
	if (Stack1._size < Stack2._size) {
		final_size = Stack1._size;
	}
	else { final_size = Stack2._size; }

	for (int i = 0;i < final_size;++i)
	{

		if (Stack1.arr[i] <= Stack2.arr[i]) {
			return true;
		}
		else if (Stack1.arr[i] > Stack2.arr[i])
			return false;
	}
	return Stack1 <= Stack2;
}
//  Comparision with Greater than or Equal to Operator
template<typename T>
bool operator>=(const stack<T>  &Stack1, const stack<T>  &Stack2) {
	int size1 = Stack1._size;
	int size2 = Stack2._size;
	int final_size;
	if (Stack1._size < Stack2._size) {
		final_size = Stack1._size;
	}
	else { final_size = Stack2._size; }

	for (int i = 0;i < final_size;++i)
	{

		if (Stack1.arr[i] >= Stack2.arr[i]) {
			return true;
		}
		else if (Stack1.arr[i] < Stack2.arr[i])
			return false;
	}
	return Stack1 >= Stack2;
}