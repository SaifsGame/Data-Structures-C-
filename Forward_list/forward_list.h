#pragma once

template<typename T>
struct node
{
    T Val;
    node<T>* link;
	node(){
		Val = T();
		link = nullptr;
};


template<typename T>
class forward_list{
private:
    node<T>* head;
    int n;
public:
// constructor
    forward_list(){
        this->head = new node<T>;
        this->head->link = nullptr;
        this->n = 0;
    }
// declared destructor
~forward_list(){
	node<T>* temp;
	temp = head->link;
	while(head->link != nullptr){
		head->link = temp->link;
		delete temp;
	}
	delete head;
}

    void push_front(const T &value){
    node<T>* temp = new node<T>;
    temp->Val = value;
    temp->link = head->link;
    head->link = temp;
    n++;
    }

    void pop_front(){
        if(head->link == nullptr){
            throw("List is Empty!");
            return;
        }
		// jani pop kar rahe ho tou new node ks leye bna re ho ?? new nahe aye ga yaha 
        node<T>* temp = node<T>;
        temp = head->link;
        head->link = temp->link;
        delete temp;
        --n;
    }
    void resize(int count,const T &num = T()) {
		if(count<0){
			throw("Count must be Positive!");
		}
		if (count == n) {
			throw("Size is Same");
		}
		
		if (count > n) {
			int x = count - n;
			for (int i = 0;i < x;i++) {
				//if (head->link == head)
				//{
				//	break;
                 //}
            node<T>* temp = new node<T>;
			temp->Val = num;
			temp->link = head->link;
			head->link= temp;
			++n;
		}
		        return;
		}

			if (count == 0)  // Delete All Nodes
			{ 
				node<T>* current = head->link;
				while(current != head){
					node<T>* temp = current;
					current = current->link;
					delete temp;
				}
				head->link = head; // Only Dummy Node remains
				this->n=0;
				return;
			}
		
			// find the Count -th Node
			node<T>* current = head->link;
			for(int i=1;i<count;i++){
				current =current->link;
			}

			// Current now points to last node as we want to Keep.
			node<T>* toDelete = current->link;
			current->link = head;
			while(toDelete!= head){
				node<T>* temp = toDelete;
				toDelete = toDelete->link;
				delete temp;
				--n;
			}
			this->n = count; //adjust n to count.		
	}

    T front() const{
        if(empty()){
            throw("List Underflow!");
            return;
        }
        return head->link->Val;
    }

    bool empty() const{
        return head->link == nullptr;
    }
    
    int size() const{
        if(empty()){
         throw("List Underflow!");  
        }
        return this->n;
    }

    void unique() {
		node<T>* current = head->link;
		while (current!= nullptr && current->link != nullptr) {
			if (current->Val == current->link->Val) {
				node<T>* temp = current->link;
				current->link = temp->link;
				delete temp;
				--n;
			}
			else {
				current = current->link;
			}
		}
	}

    void display() const {
    if(head->link == nullptr){
		throw("List is Empty");
		return;
	}
		node<T>* temp = head->link;
		while (temp != nullptr) {
	
		std::cout << temp->Val << "  ";
			temp = temp->link;
		 
		}
	}

	class iterator{
    private: 
	node<T> *ptr;
	
	
	friend class forward_list;

	public:
	 iterator(){
		this->ptr= nullptr;
	 }

	 T& operator* (){  // Dereferencing Operator Overloading
		return ptr->Val;
	 }
    
	iterator& operator++(){ // Pre Increment Operator Overloading
		ptr = ptr->link;
		return *this;
	} 
    
	iterator& operator++(int){ // Post Increment Operator Overloading
		iterator temp;
		temp.ptr = ptr;  // or We Cam Do: temp=this;
		ptr = ptr->link;
		return temp;
	} 
    
	T operator->(){ // this Operator Overloading
    return ptr->Val;
	}
	 
	bool operator!=(const iterator &rhs){ // Not Equal to Operator Overloading
    return this->ptr != rhs.ptr;
	}
    
	bool operator==(const iterator &rhs){ // Equal Equal to Operator Overloading
    return this->ptr == rhs.ptr; 
	}

	};

	// Container Funcion using iterator sub class
    
	iterator begin() const{
	iterator  it;
    it.ptr = head->link;
    return it;
    }  
	iterator end()const {
	iterator  it;
    it.ptr= nullptr;
	return it;
	}
};
