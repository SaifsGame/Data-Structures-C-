#include<iostream>
#include"forward_list.h"

int main(){
 
    forward_list<int> f;
    
    //Using push_front Function
    f.push_front(4);
    f.push_front(5);
    f.push_front(7);
    f.push_front(6);
    f.push_front(6);
    f.push_front(6);
    f.push_front(10);
    std::cout<<"\n-----------------------------------\n";
    std::cout<<"\n Total Element in the List:\n";
    f.display();
    std::cout<<"\n-----------------------------------\n";
    std::cout<<"\n Total Size of the List: "<<f.size();
    
    // Using Iterator Class Functions
    std::cout<<"\n-----------------------------------\n";
    std::cout<<"Displaying using Iterator:\n";
    forward_list<int>::iterator it;
    it = f.begin();
    while(it !=f.end()){
        std::cout<<*it<<"  ";
        ++it;
    }
    std::cout<<"\n-----------------------------------\n";
    
    //Using pop_front Function
    f.pop_front();
    //f.pop_front();
    //f.pop_front();
    //f.pop_front();
    std::cout<<"\n Total Element after pop() in the List:\n";
    f.display();
    std::cout<<"\n-----------------------------------\n";
    std::cout<<"\n Total Element after Unique() in the List:\n";
    f.unique();
    f.display();
    std::cout<<"\n-----------------------------------\n";
    f.begin();

    return 0;
}
