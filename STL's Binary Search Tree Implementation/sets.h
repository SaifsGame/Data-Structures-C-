#pragma once
#include"tnode.h"

template<typename key_type>
class set {
private:
	tnode<key_type> *head, *succ;
	int n; //for size of tree

	
public:
	class iterator; // Declaration  of Iterator Class
	set() {
		this->head = new tnode<key_type>;
		head->left = head->right = head->parent = head;
		this->n = 0;
		head->is_nill = true;
	}

	void insert(const key_type &KEY) {


		tnode<key_type> *nn = new tnode<key_type>;
		nn->left = nn->right = nn->parent = head;
		nn->key = KEY;
		nn->is_nill = false;
		n++;
		if (head->parent == head) {
			head->parent = nn;
			//head->left = nn;
			//head->right = nn;
			return;
		}

		tnode<key_type> *temp = head->parent;
		while (true)
		{
			if (KEY == temp->key) {
				delete nn;
				throw("Duplicate Value NOT ALLOWED!");
			}
			if (KEY < temp->key) {
				if (temp->left != head) {
					temp = temp->left;
				}
				else {
					nn->parent = temp;
					temp->left = nn;
					break;
				}
			}
			else if (KEY > temp->key) {
				if (temp->right != head) {
					temp = temp->right;
				}
				else {
					nn->parent = temp;
					temp->right = nn;
					break;
				}
			}
		}
	}

	iterator find(const key_type &key) {
		tnode<key_type> *ptr;
		ptr = head->parent;
		while (ptr!=head) {
			if (key == ptr->key)
				break;
			else if (key < ptr->key)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		iterator it;
		it.ptr = ptr;
		return it;
	}
	
	void erase(iterator it) {
		tnode<key_type>* to_del = it.ptr;

		if(to_del==head || to_del->is_nill){
			return;
		}
		// Case: 1 If To Delete is a Leaf Node
		if (to_del->left == head && to_del->right == head) {
			if (to_del->parent->right == to_del) {
				to_del->parent->right = head;
			}
			else {
				to_del->parent->left = head;
			}
			delete to_del;
		
		}

 
		// case : 2 if node has left child only
		else if (to_del->left != head && to_del->right == head) {
			if (to_del->parent->left == to_del) {
				to_del->parent->left = to_del->left;
			}
			else {
				to_del->parent->right = to_del->left;
			}

			to_del->left->parent = to_del->parent;
			delete to_del;
		
		}

		// Case : 3 // if node has  Right child only
		else if(to_del->right != head && to_del->left == head) {
			if (to_del->parent->right == to_del) {
				to_del->parent->right = to_del->right;
			}
			else {
				to_del->parent->left = to_del->right;
			}
			to_del->right->parent = to_del->parent;
			delete to_del;
		
		}

		// Case : 4 // if node has  Both child only
		else if (to_del->left != head && to_del->right != head) {
	    tnode<key_type>* succ = successor(to_del);

		to_del->key = succ->key;

		iterator succ_it(succ);
		erase(succ_it);

		return;
		}

		tnode<key_type>* child;
		if(to_del->left != child){
			child = to_del->left;
		} else{
        child = to_del->right;
		}

		if (to_del->parent == head){
			head->parent = child;
		} else{
			if(to_del->parent->left == to_del){
				to_del->parent->left = child;
			}
			else{
				to_del->parent->right= child;
			}
		}

     delete to_del;
		--n;
	}
	tnode<key_type>* successor(tnode<key_type>* ptr) {
		tnode<key_type>* temp = ptr->right;
		while (temp->left != head) {
			temp = temp->left;
		}
		return temp;
	}
	bool empty() const {
		return head->parent == head;
	}

	int size() const {
		return n;
	}

	class iterator {
	private:
		tnode<key_type> *ptr;

	public:
		iterator() {
			ptr = nullptr;
		}

		iterator(tnode<key_type> *p){
			this->ptr = p;
		}
		friend class set;

		key_type& operator*() {
			return ptr->key;
		}

		key_type* operator->() {
			return &ptr->key;
		}

		bool operator==(const iterator& other) {
			return ptr == other.ptr;
		}

		bool operator!=(const iterator& other) {
			return ptr != other.ptr;
		}
	};

	iterator begin() {
		iterator it;
		it.ptr = head->parent;
		return it;
	}
	iterator end() {
		iterator it;
		it.ptr = head;
		return it;
	}

};