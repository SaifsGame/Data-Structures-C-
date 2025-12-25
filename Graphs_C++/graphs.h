#pragma once
#include<forward_list>


template<typename V , typename E>
class graphs{
private:
    std::forward_list<std::pair<int ,E>> *edge;
    V *vertices;
    int g_size;
    int n; // no of elements
    
    void grow_graph(int new_size){

    }

    int get_index(const V &v) const {
    for(int i=0;i<n;++i){
    if(vertices[i] == v){
        return i;
    }
    }
    return -1;
    }

public:
    graphs(int S = 100){
        this->g_size = S;
        this->edge = new std::forward_list<std::pair<int ,E>>[g_size];
        this->n = 0;
        this->vertices = new V[g_size];
    }
    ~graphs(){
        delete[] edge;
        delete[] vertices;
    }
    void add_vertex(const V &v){
        vertices[n] = v;
        ++n;
    }

    void add_edges(const V &s , const V &d , const E &w){
        int s_i, d_i;
        s_i = get_index(s);
        d_i = get_index(d);
        edge[s_i].push_front({d_i, w});
    }

    void clear(){
        for(int i = 0; i<n ; ++i){
            edge[i].clear();
        }
        this->n = 0;
    }

    bool is_empty(){
        return this->n == 0;
    }

    bool is_full(){
        return g_size == n;
    }

    E weight(const V &s, const V &d) const{
        int s_i, d_i;
        s_i = get_index(s);
        d_i = get_index(d);
    typename std::forward_list<std::pair<int ,E>>::iterator it;
        it = edge[s_i].begin();
        while(it != edge[s_i].end()){
            if(it->first == d_i){
                return it->second;
            }
            ++it;
        }
        throw("Edge Does not Exist");
    }

    std::forward_list<V> neighbor(const V &v) const{
        int v_i;
        v_i = get_index(v);
        std::forward_list<V> F;
        typename std::forward_list<std::pair<int ,E>>::iterator it;
        it = this->edge[v_i].begin();
        while(it != edge[v_i].end()){
            F.push_front(vertices[it->first]);
            ++it;
        }
        return F;

    }


    bool depth_first_search(const V &s , const V &d){
    int s_i = get_index(s);
    int d_i = get_index(d);
    bool *marked = new bool[n];
    for(int i=0 ; i<n;i++){
        marked[i] = false;
    }
    std::stack<int> stk;
    stk.push(s_i)    
    while(!stk.empty()){

    V current = stk.top();

    stk.pop();   

        if(current == d_i){
        delete[] marked;
            return true;
        }

    if(!marked[current]){
        marked[current] = true;

    typename std::forward_list<std::pair<int ,E>>::iterator it;
    it = this->edge[v_i].begin();   
    while(it != this->edge[v_i].end()){
    
        int neighbor_i = it->first;
     if (!marked[neighbor_i]){
        stk.push(neighbor_i);
     }
     ++it;
    }
    
    }
    return false;
    }
    }

};