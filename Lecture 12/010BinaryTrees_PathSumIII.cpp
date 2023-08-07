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


long long countPaths(TreeNode* root, long long targetSum) {

	// base case

	if (root == NULL) {
		// tree is empty
		return 0;
	}

	// recursive case

	// count no. of paths starting from root that sum upto targetSum

	long long count = 0;

	// 1. ask your friend to count no. of paths  starting from the root in the leftSubtree that sum upto targetSum-root->val

	count += countPaths(root->left, targetSum - root->val);

	// 2. ask your friend to count no. of paths  starting from the root in the rightSubtree that sum upto targetSum-root->val

	count += countPaths(root->right, targetSum - root->val);

	count += root->val == targetSum ? 1 : 0;

	return count;

}


int pathSum(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		// tree is empty
		return 0;
	}

	// recursive case

	// 1. recursively, count no. of paths in the leftSubtree that sum upto 't'

	int X = pathSum(root->left, targetSum);

	// 2. recursively, count no. of paths in the rightSubtree that sum upto 't'

	int Y = pathSum(root->right, targetSum);

	// 3. count no. of paths starting from the root that sum upto 't'

	int Z = countPaths(root, targetSum);

	return X + Y + Z;


}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << pathSum(root, targetSum) << endl;

	return 0;
}