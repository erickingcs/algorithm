/*

 Populating Next Right Pointers in Each Node

 Given a binary tree

 struct TreeLinkNode {
   TreeLinkNode *left;
   TreeLinkNode *right;
   TreeLinkNode *next;
 }

 Populate each next pointer to point to its next right node.
 If there is no next right node, the next pointer should be set to NULL.

 Initially, all next pointers are set to NULL.

 Note:

 You may only use constant extra space.
 You may assume that it is a perfect binary tree
 (ie, all leaves are at the same level, and every parent has two children).

 For example,
 Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

 After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

 */

#include <iostream>
#include <queue>

using namespace std;

//Definition for binary tree
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) :
        val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

class Solution
{
public:
    void levelOrderTraversal(TreeLinkNode *root)
    {
        queue<TreeLinkNode*> q;
        TreeLinkNode *cur = root;

        q.push(cur);
        int levelSize = 0;

        while (!q.empty()) {
            // judge whether start a new level
            if (levelSize == 0) {
                levelSize = q.size();
            }

            cur = q.front();
            q.pop();
            levelSize--;
            if (levelSize != 0)
                cur->next = q.front();

            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

    void connect(TreeLinkNode *root)
    {
        if (!root)
            return;
        levelOrderTraversal(root);
    }
};

void print_tree_next_value(TreeLinkNode *root)
{
    if (root) {
        if (root->next) {
            cout << root->val << ends << root->next->val << endl;
        }
        print_tree_next_value(root->left);
        print_tree_next_value(root->right);
    }
}

int main(int argc, char *argv[])
{
    Solution sol;

    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    print_tree_next_value(root);
    sol.connect(root);
    print_tree_next_value(root);

    return 0;
}
