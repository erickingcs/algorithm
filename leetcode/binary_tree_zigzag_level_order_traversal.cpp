/*

 Binary Tree Zigzag Level Order Traversal

 Given a binary tree, return the zigzag level order traversal of its nodes' values.
 (ie, from left to right, then right to left for the next level and alternate between).

 For example:
 Given binary tree {3,9,20,#,#,15,7},

 return its zigzag level order traversal as:
 [
 [3],
 [20,9],
 [15,7]
 ]

 */

#include <iostream>
#include <vector>
#include <queue>

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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		queue<TreeNode*> q;
		TreeNode *cur = root;
		vector<vector<int>> ret;

		if (cur == nullptr)
			return ret;
		else
			q.push(cur);

		int levelSize = 0;
		int level = -1;
		bool left = false;

		while (!q.empty()) {
			// judge whether start a new level
			if (levelSize == 0) {
				levelSize = q.size();
				level++;
				ret.push_back(vector<int>()); //
				left = !left;
			}

			cur = q.front();
			q.pop();
			levelSize--;

			// add element for this level
			if (left) {
				ret[level].push_back(cur->val);
			} else {
				ret[level].insert(ret[level].begin(), cur->val);
			}

			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
		}

		return ret;
	}
};

int main(int argc, char *argv[]) {
	Solution sol;

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	vector<vector<int>> ret = sol.zigzagLevelOrder(root);

	for (auto &row : ret) {
		for (auto col : row)
			cout << col << ends;
		cout << endl;
	}

	return 0;
}
