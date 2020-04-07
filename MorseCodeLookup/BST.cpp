#include "BST.h"

BST::BST(ifstream &file) {
	char c;
	string str;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> c;
			file >> str;
			insert(root, c, str);
		}
	}

}

bool BST::insert(BSTNode *node, char c, string str) {
	if (node->getCharacter() == c)
		return false; // node already exists

	else if (node->getCharacter() > c) {
		if (node->left == nullptr)
			node->left = new BSTNode(c, str);
		
		else {
			if (insert(node->left, c, str))
				if (node->left->getBalance() < -1 ||
					node->left->getBalance() > 1)
					node->rebalance(node->left);
		}
	} else if (node->getCharacter() < c) {
		if (node->right == nullptr)
			node->right = new BSTNode(c, str);

		else {
			if (insert(node->right, c, str))
				if (node->right->getBalance() < -1 ||
					node->right->getBalance() > 1)
					node->rebalance(node->right);
		}
	}

	if (node->getBalance() != 0) {
		return true;
	}

	return false;
}