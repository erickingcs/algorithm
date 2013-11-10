/*

 Validate Binary Search Tree

 Given a binary tree, determine if it is a valid binary search tree (BST).

 Assume a BST is defined as follows:

 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.

 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool isValidBST(TreeNode *root) {
		vector<int> ret;
		stack<TreeNode*> s;
		TreeNode *cur = root;
		TreeNode *prev = nullptr; // previous node of inorder traverse

		while (cur || !s.empty()) {
			if (cur) {
				s.push(cur);
				cur = cur->left;
			} else {
				cur = s.top();
				s.pop();

				// judge
				if (prev == nullptr)
					prev = cur; // first node in inorder traverse
				else {
					if (prev->val >= cur->val) // =
						return false;
					prev = cur;
				}
				cur = cur->right;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[]) {
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);

	bool ret = sol.isValidBST(root);
	cout << ret << endl;

	return 0;
}
