#include<iostream>


struct node {
	int value;
	node* link;
};

class queue {
private:
	int n;
	node* _front;
	node* _back;
public:
	queue() {
		n = 0;
		_front = nullptr;
		_back = nullptr;
	}
	int front() {
		if (_front == nullptr) {
			throw std::runtime_error("Queue Underflow!");
		}
		return _front->value;
	}
	int back() {
		if (_back == nullptr) {
			throw std::runtime_error("Queue Underflow!");
		}
		return _back->value;
	}

	void push(const int val) {

		node* temp;
		temp = new node; //todo: Deallocate this temp in POP function or Destructor
		temp->value = val;
		temp->link = nullptr;
		if (n == 0) {
			_back = temp;
			_front = temp;
		}
		else {
			_back->link = temp;
			_back = temp;
		}

		++n;
	}

	void pop() {
        if(empty()){
        throw std::runtime_error("Queue Underflow!");
        }
		node* temp;
		temp = _front;
		_front = _front->link;
		delete temp;
		n--;
		if (_front == nullptr) {
			_back = nullptr;
		}
	}
	int size() {
		return n;
	}

	bool empty() {
		if (_front == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
        
	~queue() {
		while (_front!=nullptr)
		{
			pop();
		}
	}
	
};
int main(){
 
    queue q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	std::cout<<"\nThe Size of Queue is: " << q.size();
	if (q.empty()) {
		std::cout << "\n Queue is Empty!\n";
	}
	else {
		std::cout << "\n Queue is NOT Empty.\n";
	}
	std::cout << "\nFront Element in Queue: " << q.front();
	std::cout << "\nBack Element in Queue: " << q.back();
	q.pop();
    q.pop();
    q.pop();
    //q.pop();
	std::cout << "\nFront Value after POP(): " << q.front();
   

    return 0;
}