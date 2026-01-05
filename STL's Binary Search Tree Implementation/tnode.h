#pragma once


template<typename key_type>
struct tnode {
	key_type key;
	tnode<key_type> *left, *right, *parent;
	bool is_nill;

	tnode() {
		this->key = key_type();
		left = right = parent = nullptr;
		this->is_nill = false;
	}
};