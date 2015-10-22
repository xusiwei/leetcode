/*
copyright xu(xusiwei1236@163.com), all right reserved.

Minimum Depth of Binary Tree
=============================

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lmd = INT_MAX, rmd = INT_MAX;
        if(root->left ) lmd = minDepth(root->left);
        if(root->right) rmd = minDepth(root->right);
        
        int md = min(lmd, rmd);
        if(md == INT_MAX) return 1;
        return 1 + md;
    }
};
