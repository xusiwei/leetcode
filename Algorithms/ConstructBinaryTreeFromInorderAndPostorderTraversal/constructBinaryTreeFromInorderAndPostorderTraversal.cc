/*
copyright xu(xusiwei1236@163.com), all right reserved.

Construct Binary Tree from Inorder and Postorder Traversal
===========================================================

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/
#include <stdio.h>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, postorder.size() - 1, inorder.size());
    }
    
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int iidx, int pidx, int len) {
        if(len <= 0) return NULL;
        if(len == 1) return new TreeNode(inorder[iidx]);
        
        int ridx = pidx; // root index of inorder.
        for(int i = 0; i < len; i++) {
            if(inorder[iidx + i] == postorder[pidx]) {
                ridx = iidx + i;
                break;
            }
        }
        
        int lefts = ridx - iidx;
        int rights = len - 1 - lefts;
        TreeNode* root = new TreeNode(postorder[pidx]);
        root->left  = build(inorder, postorder, iidx, pidx-1-rights, lefts);
        root->right = build(inorder, postorder, ridx+1, pidx-1, rights);
        return root;
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
#define ARRAYSIZE(a) sizeof(a)/sizeof(a[0])
#define TEST(a1, a2) { vector<int> v1, v2;     \
        for(int i = 0; i < ARRAYSIZE(a1); i++) \
            v1.push_back(a1[i]);               \
        for(int i = 0; i < ARRAYSIZE(a1); i++) \
            v2.push_back(a2[i]);               \
        cout << v1.size() << "," << v2.size() << endl; \
        printTree(Solution().buildTree(v1, v2)); }

    int a1[] = {1,2,3,4,5,6,7};
    int a2[] = {1,3,2,5,7,6,4};
    TEST(a1, a2);
    
    return 0;
}
