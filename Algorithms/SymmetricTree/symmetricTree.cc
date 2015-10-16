/*
copyright xu(xusiwei1236@163.com), all right reserved.

Symmetric Tree
===============

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool sym(TreeNode *A, TreeNode *B) {
        if( NULL == A && NULL == B ) return true;
        if( NULL == A && NULL != B
         || NULL != A && NULL == B ) return false;
        return A->val == B->val && sym(A->left, B->right) && sym(A->right, B->left);
    }

    bool isSymmetric(TreeNode *root) {
        if(NULL == root) return true;
        return sym(root->left, root->right);
    }
};
