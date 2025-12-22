#pragma once
#include<list>
#include<utility>
#include<functional>

template<typename K , typename T>
class unordered_map{
    private:
    std::list<std::pair<K,T>> *table;
    int m;  // for Size
    int n;  // Number of Elements
    float MLF= 1.0; // MAX LOAD FACTOR
    int hash(const K &key) const{
        std::hash<K> hasher;
        return hasher(key) % m; 
    }

    public:
    unordered_map(int S = 10){
        this->m = S;
        this->n = 0;
        this->table = new std::list<std::pair<K,T>> [m];
    }

    ~unordered_map(){
        delete[] table;
    }
    
    class iterator{
        private:
        unordered_map<K,T> *mapPTR;
        int curr_bucket;
        typename std::list<std::pair<K,T>>::iterator list_it;

        public:

        iterator(unordered_map<K,T> *ptr, int cBucket ,typename std::list<std::pair<K,T>>::iterator listIT ){
            this->mapPTR = ptr;
            this->curr_bucket = cBucket;
            this->list_it = listIT;
        }  
       //___________________________________________
        std::pair<K,T>& operator*(){
            return *list_it;
        }
        //___________________________________________
        bool operator!= (const iterator &other) const{
        
            if(curr_bucket == mapPTR->m && other.curr_bucket == mapPTR->m){
                return false;
            }
            return curr_bucket != other.curr_bucket || list_it!= other.list_it;
        }
        //___________________________________________
        iterator& operator++(){
            list_it++;
        if(list_it == mapPTR->table[curr_bucket].end()){
            while(true){
                curr_bucket++;
                if(curr_bucket >= mapPTR->m){
                    list_it = typename std::list<std::pair<K,T>>::iterator();
                    break;
                } 
                if(!mapPTR->table[curr_bucket].empty()){
                    list_it = mapPTR->table[curr_bucket].begin();
                    break;
                }
            }
        }
        return *this;
        }
    };

    //------CAPICITY--------
    bool empty() const{
        return n == 0;
    }
    //___________________________________________
    int size() const{
        return this->n;
    }
    //-------Modifiers---------
    std::pair<iterator, bool> insert(const std::pair<K,T> &p){

    if( n+1 > m * MLF){
        rehash(m * 2);
    }

        int H = hash(p.first);
        typename std::list<std::pair<K,T>>::iterator it_list = table[H].begin();
    while(it_list!= table[H].end()){
    if(it_list->first == p.first){
        return {  iterator(this , H , it_list), false } ;
    }
    ++it_list;
    }
    table[H].push_front(p);
    n++;

    return { iterator(this , H , table[H].begin()), true };
    }

    //___________________________________________
    void clear(){
        
      for(int i =0; i < m ;i++){
    
          table[i].clear();
      }
      n=0;
    }

    //___________________________________________
    bool erase(const K &key){
        int H = hash(key);
        typename std::list<std::pair<K,T>>::iterator it = table[H].begin();


        while(it != table[H].end()){
            if(it->first == key){
                table[H].erase(it);
                n--;
                return true;
            }
            it++;
        }
        return 0;
    }

    //___________________________________________
    void swap(unordered_map &other){
        
        std::swap(this->table , other.table);
        std::swap(this->n , other.n);
        std::swap(this->m , other.m);
        
    }
    
    //___________________________________________ 
    void merge(unordered_map &map){
        
        iterator it = map.begin();
        
        while(it != map.end()){
            this->insert(*it);
            
            ++it;
        }
    }
    //------LOOKUP Functions-------
    T& operator[](const K &key){

        std::pair<iterator, bool> result = insert({key,T()});


        return (*result.first).second;
    }
    //___________________________________________
    iterator find(const K &key){
        int H = hash(key);
        typename std::list<std::pair<K,T>>::iterator it = table[H].begin();
    while(it != table[H].end()){
        if(it->first == key){
            return iterator(this,H,it);
        }
        it++;
    }
    return end();
    }

    //___________________________________________
    T& at(const K &key){

        iterator it = find(key);

        if(it!=end()){
            return (*it).second;
        }

        throw("Key is Not Available in Map");
    
    }
    //___________________________________________
    int count(const K &key) const {

        int H = hash(key);
        typename std::list<std::pair<K,T>>::iterator it = table[H].begin();
        
        while(it != table[H].end()){

            if(it->first == key){
                return 1;
            }
        it++;
        }
        return 0;
    }
    //___________________________________________
    bool contains(const K &key) const {

        int H = hash(key);
        typename std::list<std::pair<K,T>>::iterator it = table[H].begin();
        
        while(it != table[H].end()){

            if(it->first == key){
                return true;
            }
        it++;
        }
        return false;
    }
    //-------------------------------------------------

    //----------- Bucket Interface --------------------

    int bucket_count() const{
        return this->m;
    }
    //___________________________________________
    int bucket_size(int index) const{
        if(index < 0 || index >=m ){
            return 0;
        }
        return table[index].size();
    }
   //___________________________________________
    int bucket(const K &key) const{
        return hash(key);
    }
   //___________________________________________ 
    iterator begin(int n){
        if(n>=m){
            return end();
        }
        return iterator(this, n , table[n].begin());
    }
    //___________________________________________
   iterator end(int n){
        if(n>=m){
            return end();
        }
        return iterator(this, n , table[n].end());
    }

    //---------------------------------------------------

    //------- HASHING Policy ----------

    float load_factor() const{
        return (float)n / m;
    }

    float max_load_factor() const{
        return this->MLF;
    }

    void max_load_factor(float x){
        this->MLF = x;
    }
    //---------------------------------------------------
    void rehash(int N){
        std::list<std::pair<K,T>> *Newtable = new std::list<std::pair<K,T>> [N];
    
        for(int i = 0; i < m ; i++){
            typename std::list<std::pair<K,T>>::iterator it = table[i].begin();
            while(it != table[i].end()){
                std::hash<K> hasher;
                int NewIndex = hasher(it->first) % N;

                Newtable[NewIndex].push_front(*it);
                it++;
            }
        }

        delete[] table;
        this->table = Newtable;
        this->m = N;

    }
    //---------------------------------------------------
    void reserve(int element_count){

        int required_buckets = (int)((float)element_count / MLF);

        if (required_buckets > this->m){
            rehash(required_buckets);
        }
    }

    //---------ITERATORS-------------
    iterator begin(){

            for(int i = 0; i < m; ++i){

                if(!table[i].empty()){
                    return iterator(this , i , table[i].begin());
                }
            }
            return end();
        }

    iterator end(){

        return iterator(this , m ,typename std::list<std::pair<K,T>>::iterator() );
        
    }

};