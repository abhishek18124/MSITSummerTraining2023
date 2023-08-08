/*

	Given a BST, design an algorithm transform it into a sorted linked list in-place.

*/

#include<iostream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


void printLinkedList(TreeNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->right;
	}

	cout << endl;
}

class Pair {

public :
	TreeNode* head;
	TreeNode* tail;
};

Pair bstToSortedLL(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		// tree is empty
		p.head = p.tail = NULL;
		return p;
	}

	// recursive case

	// 1. convert the leftSubtree into a sorted LL

	Pair left = bstToSortedLL(root->left);

	if (left.head != NULL) {
		left.tail->right = root;
		p.head = left.head;
	} else {
		p.head = root;
	}


	// 1. convert the rightSubtree into a sorted LL

	Pair right = bstToSortedLL(root->right);

	if (right.head != NULL) {
		root->right = right.head;
		p.tail = right.tail;
	} else {
		p.tail = root;
	}

	return p;

}


int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	Pair p = bstToSortedLL(root);

	printLinkedList(p.head);

	return 0;
}