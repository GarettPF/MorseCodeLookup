#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

class BSTNode {
	public: 
		char character;
		std::string code;
		BSTNode *left, *right;

		BSTNode(char c, std::string str) {
			character = c;
			code = str;
			left = right = nullptr;
		}
};

#endif // BSTDNODE_H