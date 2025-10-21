#include <iostream>
#include"stack.h"


int main()
{

	stack<int> s(10), st(30);

	// Stack No 1.
	s.push(1);
	s.push(2);
	s.push(14);

	//Stack No 2.
	st.push(1);
	st.push(1);
	st.push(1);
	
	// Display the Values
	std::cout << "Element at the Top of s Stack: " << s.top();
	if (s.empty() == false) {
		std::cout << "The Stack is NOT Empty!\n";
	}
	else {
		std::cout << "The Stack is Empty! \n";
	}

	std::cout << "\n=======Values in Both Stack=====\n";
	std::cout << "\n-----Stack No-1---\n";
	std::cout << "The Top Element in Stack 1: " << s.top();
	std::cout << "\nThe Size of the Stack 1: " << s.size() << std::endl;

	std::cout << "\n-----Stack No-2---\n";
	std::cout << "The Top Element in Stack 2: " << st.top();
	std::cout << "\nThe Size of the Stack 2: " << st.size() << std::endl;
	// ------------AFTER SWAP---------------
	s.swap(st);
	std::cout << "\n======= VALUES AFTER SWAP =========\n";
	std::cout << "\n-----Stack No-1---\n";
	std::cout << "The Top Element in Stack 1: " << s.top();
	std::cout << "\nThe Size of the Stack 1: " << s.size() << std::endl;

	std::cout << "\n-----Stack No-2---\n";
	std::cout << "The Top Element in Stack 2: " << st.top();
	std::cout << "\nThe Size of the Stack 2: " << st.size() << std::endl;

	s.pop();
	std::cout << "Value after Using POP() function = " << s.top()<<std::endl;
	std::cout << "\n CODE IS RUNNING!\n";

	//================---------STACK COMPARISION------------=====================
	std::cout << "\n[---------Stack Comparison------------]\n";
	// Comparision with Equal to Operator
	if (s == st) {
		std::cout << "\n--------> The Stacks are Equal." << std::endl;
	}
	else {
		std::cout << "\n--------> The Stacks are NOT Equal!" << std::endl;
	}
	//  Comparision with Less than Operator
	if (s < st) {
		std::cout << "\n--------> The Stack is Less than the Other." << std::endl;
	}
	else {
		std::cout << "\n--------> The Stack is NOT less than the other!" << std::endl;
	}
	
	//  Comparision with Greater than Operator
	if (s > st) {
		std::cout << "\n--------> The Stack is Greater than the Other." << std::endl;
	}
	else {
		std::cout << "\n--------> The Stack is NOT Greater than the other!" << std::endl;
	}

	//  Comparision with Less than or Equal to Operator
	if (s <= st) {
		std::cout << "\n--------> The Stack is Less than or Equal to the Other." << std::endl;
	}
	else {
		std::cout << "\n--------> The Stack is NOT less than or Equal to the other!" << std::endl;
	}

	//  Comparision with Greater than or Equal to Operator
	if (s >= st) {
		std::cout << "\n--------> The Stack is Greater than or Equal to the Other." << std::endl;
	}
	else {
		std::cout << "\n--------> The Stack is NOT Graeteer than or Equal to the other!" << std::endl;
	}
}


