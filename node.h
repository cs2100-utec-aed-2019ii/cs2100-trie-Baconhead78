#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <map>

class node{
	public:
		bool is_word;
		std::map<char, node*> children;
		node(){
			is_word = false;
		};
		node(bool v){
			is_word = v;
		};
};

#endif
