#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

// int countPaths(TreeNode* root, int targetSum) {

// 	// base case

// 	if (root == NULL) {
// 		// tree is empty
// 		return 0;
// 	}

// 	// recursive case

// 	// 1. ask your friend to count no. of paths  starting from the root in the leftSubtree that sum upto targetSum-root->val

// 	int X = countPaths(root->left, targetSum - root->val);

// 	// 2. ask your friend to count no. of paths  starting from the root in the rightSubtree that sum upto targetSum-root->val

// 	int Y = countPaths(root->right, targetSum - root->val);

// 	int Z = root->val == targetSum ? 1 : 0;

// 	return X + Y + Z;

// }


int countPaths(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		// tree is empty
		return 0;
	}

	// recursive case

	// count no. of paths starting from root that sum upto targetSum

	int count = 0;

	// 1. ask your friend to count no. of paths  starting from the root in the leftSubtree that sum upto targetSum-root->val

	count += countPaths(root->left, targetSum - root->val);

	// 2. ask your friend to count no. of paths  starting from the root in the rightSubtree that sum upto targetSum-root->val

	count += countPaths(root->right, targetSum - root->val);

	count += root->val == targetSum ? 1 : 0;

	return count;

}


int main() {

	TreeNode* root = NULL;

	int targetSum = 12;

	// root = new TreeNode(2);

	// root->left = new TreeNode(7);
	// root->left->left = new TreeNode(3);
	// root->left->left->left = new TreeNode(1);
	// root->left->left->right = new TreeNode(8);
	// root->left->right = new TreeNode(3);

	// root->right = new TreeNode(6);
	// root->right->left = new TreeNode(4);
	// root->right->right = new TreeNode(5);

	// cout << countPaths(root, targetSum) << endl;

	targetSum = 4;

	root = new TreeNode(4);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(8);
	root->left->right = new TreeNode(3);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	cout << countPaths(root, targetSum) << endl;

	return 0;
}