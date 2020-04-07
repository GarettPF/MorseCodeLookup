#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>

class BSTNode {
	private:
		char character;
		std::string code;
		int height;
		int balance;

	public: 
		BSTNode *left, *right;

		BSTNode(char c, std::string str) {
			character = c;
			code = str;
			height = 0;
			balance = 0;
			left = right = nullptr;
		}
		
		char getCharacter() { return character; };
		std::string getCode() const { return code; };

		// get height value of node
		int getHeight() {
			if (height == 0)
				return height;

			return (left->getHeight() > right->getHeight()) ?
				left->getHeight() : right->getHeight();
		}

		// get balance of tree node
		int getBalance() {
			return right->getHeight() - left->getHeight();
		}
		// set balance of tree node
		void setBalance(int i) { balance = i; }

		// functions to fix the balancing of the tree
		void rebalance(BSTNode *);
		void rotateLeft(BSTNode *);
		void rotateRight(BSTNode *);
		void rotateRightLeft(BSTNode *);
		void rotateLeftRight(BSTNode *);
};

void BSTNode::rebalance(BSTNode *n) {
	std::cout << "rebalance " << n->getCharacter();

	if (n->getBalance() == -2)
		if (n->left->getBalance() == -1) rotateRight(n);
		else if (n->left->getBalance() == 1) rotateLeftRight(n);
	if (n->getBalance() == -2)
		if (n->right->getBalance() == 1) rotateLeft(n);
		else if (n->right->getBalance() == -1) rotateRightLeft(n);
}

void BSTNode::rotateLeft(BSTNode *n) {
	std::cout << "rotateLeft " << n->getCharacter();

	BSTNode *temp = n->right;
	n->right = temp->left;
	n->height -= 1;
	temp->left = n;

	if (n == left)
		left = temp;
	else
		right = temp;
}

void BSTNode::rotateRight(BSTNode *n) {
	std::cout << "rotateRight " << n->getCharacter();

	BSTNode *temp = n->left;
	n->left = temp->right;
	n->height -= 1;
	temp->right = n;

	if (n == left)
		left = temp;
	else
		right = temp;

}

void BSTNode::rotateRightLeft(BSTNode *n) {
	n->right->left->setBalance(1);
	n->rotateRight(n->right);
	n->right->setBalance(1);
	rotateLeft(n);
}

void BSTNode::rotateLeftRight(BSTNode *n) {
	n->left->right->setBalance(-1);
	n->rotateLeft(n->left);
	n->left->setBalance(-1);
	rotateRight(n);
}

#endif // BSTDNODE_H