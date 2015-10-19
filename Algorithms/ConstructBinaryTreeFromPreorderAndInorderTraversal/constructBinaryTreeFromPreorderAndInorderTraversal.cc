/*
copyright xu(xusiwei1236@163.com), all right reserved.

Construct Binary Tree from Preorder and Inorder Traversal
==========================================================

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pidx, int iidx, int len) {
        if(len <= 0) return NULL;
        if(len == 1) return new TreeNode(inorder[iidx]);
        
        int ridx = iidx; // root index of inorder.
        for(int i = 0; i < len; i++) {
            if(inorder[iidx + i] == preorder[pidx]) {
                ridx = iidx + i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(preorder[pidx]);
        root->left  = build(preorder, inorder, pidx+1, iidx, ridx-iidx);
        root->right = build(preorder, inorder, pidx+1+(ridx-iidx), ridx+1, len-1-(ridx-iidx));
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, inorder.size());
    }
};

void printTree(TreeNode* root) {
    if(!root) return;
    
    cout << root->val << " at " << root << endl;
    if(root->left) cout << " ->" << root->left->val << " at " << root->left << endl;
    if(root->right) cout << " ->" << root->right->val << " at " << root->right << endl;
    
    printTree(root->left);
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

    int a1[] = {1, 2, 3};
    int a2[] = {1, 2, 3};
    TEST(a1, a2);
    
    
    return 0;
}
