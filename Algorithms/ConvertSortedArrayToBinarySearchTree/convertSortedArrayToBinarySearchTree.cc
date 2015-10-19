/*
copyright xu(xusiwei1236@163.com), all right reserved.

Convert Sorted Array to Binary Search Tree
===========================================

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/
#include <stdlib.h>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    TreeNode* buildBST(vector<int>& num, int begin, int end) {
        if(begin >= end) return NULL;

        int mid = begin + (end - begin)/2;

        TreeNode* root = new TreeNode(num[mid]);
        root->left  = buildBST(num, begin, mid);
        root->right = buildBST(num, mid+1, end);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& num) {
        return buildBST(num, 0, num.size());
    }
};

void printTree(TreeNode* root) {
    if(!root) return;
    
    printTree(root->left);
    cout << root->val << " at " << root << endl;
    if(root->left) cout << " ->" << root->left->val << " at " << root->left << endl;
    if(root->right) cout << " ->" << root->right->val << " at " << root->right << endl;
    
    printTree(root->right);
}

int main(int argc, char* argv[])
{
    vector<int> v;
    for(int i = 1; i < argc; i++) {
        v.push_back(atoi(argv[i]));
    }
    cout << "size:" << v.size() << endl;
    
    printTree(Solution().sortedArrayToBST(v));
    return 0;
}
