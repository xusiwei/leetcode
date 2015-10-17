/*
copyright xu(xusiwei1236@163.com), all right reserved.

Recover Binary Search Tree
===========================

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <vector>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* lst, TreeNode* rst) : val(x), left(lst), right(rst) {}
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> stack;
        TreeNode *prev, *n1, *n2;
        
        prev = n1 = n2 = NULL;
        
        // inorder traversal.
        while(stack.size() > 0 || root != NULL) {
            if(root != NULL) {
                stack.push_back(root);
                root = root->left;
            }
            else {
                root = stack.back(); stack.pop_back();
                
                // visitor.
                // swap two element in a sequence, check the neighbor pair.
                // there will have one or two unordered pair:
                //   for one pair, the endian are swaped;
                //   for two pair, p1->first and p2->second are swaped.
                if(prev != NULL && prev->val > root->val) {
                    if(n1 == NULL) n1 = prev;
                    n2 = root;
                }
                
                prev = root;
                root = root->right;
            }
        }
        swap(n1->val, n2->val);
    }
};

void inorderPrint(TreeNode* root) {
    vector<TreeNode*> stack;
    // inorder traversal.
    while(stack.size() > 0 || root != NULL) {
        if(root != NULL) {
            stack.push_back(root);
            root = root->left;
        }
        else {
            root = stack.back(); stack.pop_back();
            // visitor.
            printf("%d ", root->val);
            root = root->right;
        }
    }
    puts("");
}

int main(int argc, char* argv[])
{
    TreeNode* root;
    
    root = new TreeNode(2, 
            new TreeNode(5),
            new TreeNode(4,
                new TreeNode(3),
                new TreeNode(1)));
    inorderPrint(root);
    
    Solution().recoverTree(root);
    
    inorderPrint(root);
    return 0;
}
