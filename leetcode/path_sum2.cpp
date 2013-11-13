/*

 Path Sum II

 Given a binary tree and a sum, find all root-to-leaf paths
 where each path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

 return
 [
  [5,4,11,2],
  [5,8,4,5]
 ]

 */

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

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
	int getPathSum(vector<int> &v) {
		return accumulate(v.begin(), v.end(), 0);
	}

	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<vector<int>> ret;
		stack<TreeNode*> s;
		vector<int> v;
		TreeNode *cur = root, *prev = nullptr;

		// postorder traverse tree
		while (cur || !s.empty()) {
			if (cur) {
				s.push(cur);
				v.push_back(cur->val);
				cur = cur->left;
			} else {
				cur = s.top();

				if (cur->right && cur->right != prev) {
					cur = cur->right;
					s.push(cur);
					v.push_back(cur->val);
					cur = cur->left;
				} else {
					s.pop();
					if (!cur->left && !cur->right && getPathSum(v) == sum) {
						ret.push_back(v);
					}
					v.pop_back();
					prev = cur;
					cur = nullptr;
				}
			}
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
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(5);

	vector<vector<int>> ret = sol.pathSum(root, 7);

	for (auto &row : ret) {
		for (auto col : row)
			cout << col << ends;
		cout << endl;
	}

	return 0;
}
