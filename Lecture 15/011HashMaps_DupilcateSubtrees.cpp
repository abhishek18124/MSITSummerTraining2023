#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<string, TreeNode*> hasSeen;
set<TreeNode*> duplicateSubtreeSet;

string dfs(TreeNode* root) {

    // base case

    if (root == NULL) {
        // tree is empty
        return "X";
    }

    // recursive case

    // 1. build a unique string representatioon for the subtree rooted at the 'root' node

    string leftRepr = dfs(root->left);
    string rightRepr = dfs(root->right);

    string subtreeRepr = to_string(root->val) + "-" + leftRepr + "-" + rightRepr;

    if (hasSeen.find(subtreeRepr) != hasSeen.end()) {

        // this subtree is duplicate

        duplicateSubtreeSet.insert(hasSeen[subtreeRepr]);

    } else {

        hasSeen[subtreeRepr] = root;

    }

    return subtreeRepr;

}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

    dfs(root);

    // vector<TreeNode*> out;

    // for (TreeNode* subtree : duplicateSubtreeSet) {
    //     out.push_back(subtree);
    // }

    // return out;

    return vector<TreeNode*>(duplicateSubtreeSet.begin(), duplicateSubtreeSet.end());

}