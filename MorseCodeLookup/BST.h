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

		void storeBSTNodes(BSTNode *);
		BSTNode *buildBalanceTree(int, int);

		void print_(BSTNode *) const;
		void clear(BSTNode *);
		bool search_(BSTNode *, char, string &) const;

	public:
		BST(ifstream &); // constructor
		~BST(); // destructor

		// inserts data in original pattern
		void insert(BSTNode *&, char, string);

		// rebalances the tree to a more efficient height
		void balance();

		void print() const { print_(root); }
		bool search(char c, string &str) const { 
			return search_(root, c, str); 
		}
};

#endif