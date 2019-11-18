#ifndef TRIE_TREE_H
#define TRIE_TREE_H

#include "node.h"

class trie_tree{
	private:
		void print(node* curr, int level){
			std::cout << level;
			if (curr->children.empty()){
				std::cout << "\n";
				return;
			}else
				for (auto i : curr->children){
					std::cout << ": " << i.first << " ";
				}

			std::cout << "\n";
			for (auto i : curr->children){
				print(i.second, level+1);
			}
		};

		void erase_word(int letter_pos, node* curr, std::string word){
			auto encontrado = curr->children.find(word[letter_pos]);
			if (encontrado != curr->children.end()){
				if (letter_pos != word.size()-1)
					erase_word(letter_pos+1, encontrado->second, word);
				else
					erase_word(letter_pos, encontrado->second, word);
			}

			curr->children.erase(word[letter_pos]);
			if (curr->children.empty())
				delete curr;

			return;
		};

	public:
		node* root;

		trie_tree(){
			root = nullptr;
		};

		void insert(std::string word){
			if (root == nullptr){
				root = new node();
				node* empty = new node();
				root->children.insert({word[0], empty});
			}
			auto curr = root;
			for (auto i : word){
				auto encontrado = curr->children.find(i);
				if (encontrado == curr->children.end()){
					node* empty = new node(true);
					curr->children.insert({i,empty});
					curr = empty;
				}else{
					curr = encontrado->second;
				}
			}
			if (curr->is_word == false)
				curr->is_word = true;
		};

		bool search_by_complete_word(std::string word){
			if (root == nullptr)
				return false;
			else{
				auto curr = root;
				for (auto i : word){
					auto encontrado = curr->children.find(i);
					if (encontrado == curr->children.end())
						return false;
					else
						curr = encontrado->second;
				}
				if (curr->is_word == true)
					return true;
				else
					return false;
			}
		};

		bool search_by_prefix(char letter){
			if (root->children.find(letter) == root->children.end())
				return false;
			else
				return true;
		};

		void print(){
			auto curr = root;
			int level = 0;
			print(curr, level);
		};

		void erase_word(std::string word){
			erase_word(0, root, word);
		};

};

#endif





