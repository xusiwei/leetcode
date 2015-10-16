/*
copyright xu(xusiwei1236@163.com), all right reserved.

Same Tree
==========

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // empty tree equals empty tree.
        if( p == NULL && q == NULL ) return true;
        
        // empty tree not equals non-empty tree.
        if( p == NULL && q != NULL ) return false;
        if( q == NULL && p != NULL ) return false;
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
