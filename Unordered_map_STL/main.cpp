#include<iostream>
#include"unordered_map.h"


int main(){

unordered_map<int, int> myMap(10);
unordered_map<int, int> myMap2(10);
   myMap.insert({1,2});
   myMap.insert({2,24});
   myMap.insert({3,29});
   
    myMap[4] = 24;
    myMap[5] = 45;
    myMap[6] = 78;
    
    std::cout<<"Is My Map Empty? :"<<(myMap.empty() ? "YES" : "NO" )<<std::endl;

    std::cout<<"Current Size of the Map: "<<myMap.size()<<std::endl;

    std::cout<<"Is {"<<2<<","<<24<<"} are Available in the Map? : "<<(myMap.find(4) != myMap.end() ? "YES" : "NO");

    std::cout<<"\nIs {"<<10<<","<<579<<"} are Available in the Map? : "<<(myMap.find(10) != myMap.end() ? "YES" : "NO");

    unordered_map<int, int>::iterator it = myMap.begin();
    std::cout<<"\n-------- Map - Contents -----------\n";
    while(it!= myMap.end()){
        std::cout<<"\n --- Key: "<<(*it).first<<", ==> Value: "<<(*it).second<<std::endl;
    
     ++it;
    }

    std::cout<<"\n------ Detail of MyMap2 (After Using Swap Function)----\n";
    myMap.swap(myMap2);
    // MAP2 Inforrmation
    std::cout<<"Is My Map Empty? :"<<(myMap2.empty() ? "YES" : "NO" )<<std::endl;

    std::cout<<"Current Size of the Map: "<<myMap2.size()<<std::endl;

    std::cout<<"Is {"<<2<<","<<24<<"} are Available in the Map? : "<<(myMap2.find(4) != myMap2.end() ? "YES" : "NO");

    myMap.clear();


    return 0;
}