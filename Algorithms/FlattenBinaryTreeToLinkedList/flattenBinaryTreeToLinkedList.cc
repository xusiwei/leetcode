/*
copyright xu(xusiwei1236@163.com), all right reserved.

Flatten Binary Tree to Linked List
===================================

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

click to show hints.
Hints:

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

*/
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* L, TreeNode* R) : val(x), left(L), right(R) {}
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
    void flatten(TreeNode* root) {
        if(root == NULL || root->left == NULL && root->right == NULL) return;
        
        vector<TreeNode*> s;
        vector<TreeNode*> v;
        
        s.push_back(root);
        while( !s.empty() ) {
            TreeNode* p = s.back();
            s.pop_back();
            
            v.push_back(p);
            if(p->right) s.push_back(p->right);
            if(p->left ) s.push_back(p->left);
        }
        
        for(int i = 0; i < v.size()-1; i++) {
            v[i]->left  = NULL;
            v[i]->right = v[i+1];
        }
    }
};

void printTree(TreeNode* root)
{
    if(root == NULL) return;
    cout << root->val << ",";
    printTree(root->left);
    printTree(root->right);
}

void printTreeRight(TreeNode* root)
{
    if(root == NULL) return;
    
    while(root) {
        cout << root->val << ",";
        root = root->right;    
    }
}

int main(int argc, char* argv[])
{
    TreeNode* root = new TreeNode(1, 
                        new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                        new TreeNode(5, NULL, new TreeNode(6)));
    printTree(root); cout << endl;
    Solution().flatten(root);
    printTreeRight(root); cout << endl;
    return 0;
}
