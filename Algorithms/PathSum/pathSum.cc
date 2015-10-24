/*
copyright xu(xusiwei1236@163.com), all right reserved.

Path Sum
=========

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
    bool hasPathSumHelper(TreeNode* root, int sum, int last) {
        if(root == NULL) return false;
        
        last += root->val;
        if(root->left == NULL && root->right == NULL) {
            return last == sum;
        }
        
        return hasPathSumHelper(root->left, sum, last) 
             || hasPathSumHelper(root->right, sum, last);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSumHelper(root, sum, 0);
    }
};
