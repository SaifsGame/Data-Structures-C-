
#include <iostream>
#include"sets.h"

int main()
{
	set<int> s;
	s.insert(6);
	s.insert(10);
	s.insert(4);
	s.insert(3);
	std::cout << "\nSize of Tree: "<<s.size() << std::endl;
	std::cout << "Tree is Empty Yes? or No? : " << (s.empty() ? "Yes" : "No")<<std::endl;
    
	set<int>::iterator add = s.find(10);
	if(add != s.end()){
	s.erase(add);
	} else {
		std::cout<<"Value Not Found!\n";
	}
	std::cout << "Size of Tree After Using Erase Func : " << s.size() << std::endl;
	std::cout << "Code is Running!!";
}


