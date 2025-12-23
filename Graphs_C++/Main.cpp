#include<iostream>
#include"graphs.h"

int main(){

    graphs<char, int> G;
    
    // Vertices
    G.add_vertex('A');
    G.add_vertex('B');
    G.add_vertex('C');
    G.add_vertex('D');


    // Edges
    G.add_edges('A' , 'C' , 1);
    G.add_edges('C' , 'B' , 2);
    G.add_edges('B' , 'D' , 3);
    G.add_edges('D' , 'A' , 4);
    
    //---- Display Section ----------
    std::cout<<"Is this an Empty Graph? :"<<(G.is_empty() ? "YES!" : "NO!")<<std::endl;
    std::cout<<"------------------------------------\n";
    std::cout<<"Is Graph if Full? :"<<(G.is_full() ? "YES!" : "NOT Full!")<<std::endl;
    
    std::cout<<"\nWeight of the 'A','C'in Graph's Edges(Using weight func) :"<<G.weight('A','C')<<std::endl;
    std::cout<<"\nWeight of the 'C','B'in Graph's Edges(Using weight func) :"<<G.weight('C','B')<<std::endl;
    std::cout<<"\nWeight of the 'B','D'in Graph's Edges(Using weight func) :"<<G.weight('B','D')<<std::endl;
    std::cout<<"\nWeight of the 'D','A'in Graph's Edges(Using weight func) :"<<G.weight('D','A')<<std::endl;
    
    //----- Displaying Neighbors --------
    std::forward_list<char> N;
    N = G.neighbor('A');
 
   
    //-----------------------------------

    // Using Clear Function to Free Up Some Extra Memory ;)
    G.clear();
    return 0;
}