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


// vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

// 	// todo ...
// }


void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& paths) {

	// base case

	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		if (root->val == targetSum) {
			path.push_back(root->val);
			// for (int i = 0; i < path.size(); i++) {
			// 	cout << path[i] << " ";
			// }
			// cout << endl;
			paths.push_back(path);
			path.pop_back();
		}

		return;
	}

	// recursive case

	// use the root node

	path.push_back(root->val);

	helper(root->left, targetSum - root->val, path, paths);
	helper(root->right, targetSum - root->val, path, paths);

	path.pop_back();


}


int main() {

	TreeNode* root = NULL;

	root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	int targetSum = 22;

	vector<vector<int>> paths;
	vector<int> path;

	helper(root, targetSum, path, paths);

	for (vector<int> path : paths) {
		for (int node : path) {
			cout << node << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}