/*
copyright xu(xusiwei1236@163.com), all right reserved.

Balanced Binary Tree
=====================

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
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
    static int depth(TreeNode *root) {
        if(root == NULL) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        if(!isBalanced(root->left) || !isBalanced(root->right)) return false;
        return abs(depth(root->left) - depth(root->right)) <= 1;
    }
};
