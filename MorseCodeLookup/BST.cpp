#include "BST.h"

void BST::storeBSTNodes(BSTNode *root) {
	// base case
	if (root == nullptr)
		return;

	// store nodes in Inorder (sorted order)
	storeBSTNodes(root->left);
	nodes.push_back(root);
	storeBSTNodes(root->right);
}

BSTNode *BST::buildBalanceTree(int lhs, int rhs) {

	// base case
	if (lhs > rhs)
		return nullptr;

	// Get the middle element and make it root
	int mid = (lhs + rhs)/2;
	BSTNode *node = nodes[mid];

	// Using index in order traversal, contruct left and right subtrees
	node->left = buildBalanceTree(lhs, mid-1);
	node->right = buildBalanceTree(mid+1, rhs);

	return node;
}

void BST::print_(BSTNode *node) const {
	if (node) {
		print_(node->left);
		cout << node->character << " : " << node->code << endl;
		print_(node->right);
	}
}

void BST::clear(BSTNode *node) {
	if (node) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

bool BST::search_(BSTNode *node, char c, string &str) const {
	if (c == node->character) {
		str = node->code;
		return true;
	} else if (c > node->character)
		return search_(node->right, c, str);
	else if (c < node->character)
		return search_(node->left, c, str);
}

BST::BST(ifstream &file) {
	char c;
	string str;
	root = nullptr;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> c;
			file >> str;
			insert(root, c, str);
		}
	} else cout << "File could not be found.\n";
}

BST::~BST() {
	clear(root);
}

void BST::insert(BSTNode *&node, char c, string str) {
	if (node == nullptr)
		node = new BSTNode(c, str);
	else if (c < node->character)
		insert(node->left, c, str);
	else
		insert(node->right, c, str);
}

void BST::balance() {
	// store nodes of given BST in sorted order
	storeBSTNodes(root);

	// constructs BST from nodes[] in balanced form
	int n = nodes.size();
	root = buildBalanceTree(0, n-1);
}