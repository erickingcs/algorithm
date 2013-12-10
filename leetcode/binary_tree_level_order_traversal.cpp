/*

 Binary Tree Level Order Traversal

 Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

 return its level order traversal as:
 [
 [3],
 [9,20],
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
        val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        queue<TreeNode*> q;
        TreeNode *cur = root;
        vector<vector<int>> ret;

        if (cur == nullptr)
            return ret;
        else
            q.push(cur);

        int levelSize = 0;
        int sub = -1;

        while (!q.empty()) {
            // judge whether start a new level
            if (levelSize == 0) {
                levelSize = q.size();
                sub++;
                ret.push_back(vector<int>()); //
            }

            cur = q.front();
            q.pop();

            // add element for this level
            ret[sub].push_back(cur->val);
            levelSize--;

            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ret = sol.levelOrder(root);

    for (auto &row : ret) {
        for (auto col : row)
            cout << col << ends;
        cout << endl;
    }

    return 0;
}
