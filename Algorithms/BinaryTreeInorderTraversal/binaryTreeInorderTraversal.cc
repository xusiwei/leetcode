/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Inorder Traversal
==============================

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#ifdef RECUSIVE

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
    
    void inOrder(TreeNode *root, vector<int> &res) {
        if(root == NULL) return;
        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
};

#else  // RECUSIVE

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        vector<int> result;
        
        while(stack.size() > 0 || root != NULL) {
            if(root != NULL) {
                stack.push_back(root);
                root = root->left;
            }
            else {
                root = stack.back();
                stack.pop_back();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};

#endif // RECUSIVE

int main(int argc, char* argv[])
{
    int root = 0;
    TreeNode* nodes[20] = {0};
    typedef int branch[2];
    
    for(int i = 1; i < sizeof(nodes)/sizeof(nodes[0]); i++) {
        nodes[i] = new TreeNode(i);
    }

#if 1
    // {4, 2, 6, 1, 3, 5, 7}
    //       4
    //     /   \
    //    2     6
    //   / \   / \
    //  1   3 5   7
    root = 4;
    nodes[4]->left  = nodes[2];
    nodes[4]->right = nodes[6];
    nodes[2]->left  = nodes[1];
    nodes[2]->right = nodes[3];
    nodes[6]->left  = nodes[5];
    nodes[6]->right = nodes[7];
#endif

#if 0
/*
   1
  / \
 2   3
    /
   4
    \
     5
*/ 
    root = 1;
    nodes[1]->left  = nodes[2];
    nodes[1]->right = nodes[3];
    nodes[3]->left  = nodes[4];
    nodes[4]->right = nodes[5];
#endif

#if 0
/*
   1
    \
     2
    /
   3
*/
    root = 1;
    nodes[1]->right = nodes[2];
    nodes[2]->left  = nodes[3];
#endif

    vector<int> result = Solution().inorderTraversal(nodes[root]);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ",";
    }
    cout << endl;
    return 0;
}
