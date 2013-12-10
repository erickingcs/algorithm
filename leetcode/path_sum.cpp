/*

 Path Sum

 Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 such that adding up all the values along the path equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
        val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    int getPathSum(vector<int> &v)
    {
        return accumulate(v.begin(), v.end(), 0);
    }

    bool hasPathSum(TreeNode *root, int sum)
    {
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
                    if (!cur->left && !cur->right && getPathSum(v) == sum)
                        return true;
                    v.pop_back();
                    prev = cur;
                    cur = nullptr;
                }
            }
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << sol.hasPathSum(root, 7) << endl;
    cout << sol.hasPathSum(root, 4) << endl;

    return 0;
}
