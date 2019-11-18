#include <iostream>
#include "trie_tree.h"


int main(){
	trie_tree trie;
	trie.insert("hola");
	trie.insert("profe");
	trie.insert("perdon");
	trie.insert("por");
	trie.insert("la");
	trie.insert("demora");

	trie.print();

	if (trie.search_by_complete_word("hola"))
		std::cout << "si existe la palabra \n";
	else
		std::cout << "NO existe la palabra \n";

	trie.erase_word("hola");

	if (trie.search_by_complete_word("hola"))
		std::cout << "si existe la palabra \n";
	else
		std::cout << "NO existe la palabra \n";

	trie.print();
}
