/*

 Flatten Binary Tree to Linked List

 Given a binary tree, flatten it to a linked list in-place.

 For example,
 Given

         1
        / \
       2   5
      / \   \
     3   4   6
 The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

 */

#include <iostream>
#include <stack>

using namespace std;

// Definition for binary tree
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
	void flatten(TreeNode *root) {
		stack<TreeNode*> s;
		TreeNode *cur = root;
		TreeNode *prev = nullptr;

		while (cur || !s.empty()) {
			if (cur) {
				s.push(cur);
				prev = cur; // record previous node of preorder traversal
				cur = cur->left;
			} else {
				cur = s.top();
				s.pop();

				// in general preorder traversal: cur = cur->right;
				// here we break the node who has right child

				// three cases:
				//  a) tree has no child
				//  b) only have right child
				//  c) has left and right child
				if (cur->right && prev->right != cur->right) { // case c
					prev->right = cur->right;
					cur->right = nullptr;
					cur = prev->right;
				} else {
					cur = cur->right;  // case a or b
				}
			}
		}

		// swap left and right pointer if left is not nullptr
		// after that, only right child is set
		cur = root;
		while (cur) {
			if (cur->left) {
				cur->right = cur->left;
				cur->left = nullptr;
			}
			cur = cur->right;
		}
	}
};

void print_tree_preorder(TreeNode *root) {
	if (root) {
		cout << root->val << ends;
		print_tree_preorder(root->left);
		print_tree_preorder(root->right);
	}
}

void print_tree_inorder(TreeNode *root) {
	if (root) {
		print_tree_inorder(root->left);
		cout << root->val << ends;
		print_tree_inorder(root->right);
	}
}

int main(int argc, char *argv[]) {
	Solution sol;

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	print_tree_preorder(root);
	cout << endl;
	print_tree_inorder(root);
	cout << endl;

	sol.flatten(root);

	print_tree_preorder(root);
	cout << endl;
	print_tree_inorder(root);
	cout << endl;

	return 0;
}
