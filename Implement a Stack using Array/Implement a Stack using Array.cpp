#include <iostream>
#include "stack.h"
int main()
{
    stack s(20);
    s.push(60);
    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    std::cout << "Top element : " << s.topValue() << std::endl;
    std::cout << " Size of Stack is " << s.sizeofStack()<<std::endl;
    if (s.empty()) {
        std::cout << "The Stack is Empty!" << std::endl;
    }
    else {
        std::cout << "The Stack is NOT Empty.\n";
    }
    s.pop();
    std::cout << "Top element after pop() : " << s.topValue();
    s.display();
}

