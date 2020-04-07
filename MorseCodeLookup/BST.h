#ifndef BST_H
#define BST_H

#include <fstream>
#include "BSTNode.h"
using namespace std;

class BST {
	
	private:
		BSTNode *root;
		unsigned int numItems;

	public:
		BST(ifstream &); // constructor
		~BST(); // destructor

		bool insert(BSTNode *, char, string);

};

#endif