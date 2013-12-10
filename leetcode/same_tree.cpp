/*

 Same Tree

 Given two binary trees, write a function to check if they are equal or not.

 Two binary trees are considered equal if they are structurally identical
 and the nodes have the same value.

 */

#include <iostream>

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode *t1 = new TreeNode(0);
    t1->left = new TreeNode(1);

    TreeNode *t2 = new TreeNode(1);
    t2->right = new TreeNode(0);

    TreeNode *t3 = new TreeNode(2);
    t3->left = new TreeNode(3);
    t3->right = new TreeNode(1);

    TreeNode *t4 = new TreeNode(2);
    t4->left = new TreeNode(4);
    t4->right = new TreeNode(5);
    t4->right->left = new TreeNode(3);
    t4->right->left->right = new TreeNode(1);

    cout << sol.isSameTree(t1, t1) << endl;
    cout << sol.isSameTree(t2, t2) << endl;
    cout << sol.isSameTree(t3, t3) << endl;
    cout << sol.isSameTree(t4, t4) << endl;
    cout << sol.isSameTree(t1, t2) << endl;

    return 0;
}
