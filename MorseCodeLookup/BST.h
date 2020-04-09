#ifndef BST_H
#define BST_H

#include <fstream>
#include <vector>
#include "BSTNode.h"
using namespace std;

class BST {
	
	private:
		BSTNode *root;
		vector<BSTNode *> nodes;

		// stores the nodes into an array
		void storeBSTNodes(BSTNode *);

		// builds the tree in a balanced form
		BSTNode *buildBalanceTree(int, int);

		// print function with access to private members
		void print_(BSTNode *) const;

		// clear function for deconstructor
		void clear(BSTNode *);

		// search function with access to private members
		bool search_(BSTNode *, char, string &) const;

	public:
		BST(ifstream &); // constructor
		~BST(); // destructor

		// inserts data in original pattern
		void insert(BSTNode *&, char, string);

		// rebalances the tree to a more efficient height
		void balance();

		// prints tree nodes
		void print() const { print_(root); }

		// search for morse code based on input character
		bool search(char c, string &str) const { 
			return search_(root, c, str); 
		}
};

#endif