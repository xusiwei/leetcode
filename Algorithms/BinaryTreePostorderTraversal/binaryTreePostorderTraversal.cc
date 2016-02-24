/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Postorder Traversal
================================

Given a binary tree, return the postorder traversal of its nodes' values.


For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3



return [3,2,1].


Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <stdlib.h>
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
#ifdef RECURSIVE
    void postorderTraversalHelper(vector<int>& result, TreeNode* root) {
        if (root == NULL) return;
        postorderTraversalHelper(result, root->left);
        postorderTraversalHelper(result, root->right);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalHelper(result, root);
        return result;
    }

#else // RECURSIVE

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> stack;
        TreeNode* p = root;
        TreeNode* last = NULL;
        
        while (stack.size() > 0 || p != NULL) {
            if (p != NULL) {
                stack.push_back(p);
                p = p->left;
                continue;
            }
            TreeNode* n = stack.back();
            if (n->right != NULL && n->right != last) {
                p = n->right;
                continue;
            }
            stack.pop_back();
            result.push_back(n->val);
            last = n;
            
        }
        return result;
    }
#endif // RECURSIVE
};

template<typename Vector>
void printVector(Vector v)
{
    cout << "[";
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "]\n" : ",");
    }
}

int main(int argc, char* argv[])
{
#define TEST(expr) do { \
        TreeNode* root = expr; \
        printVector(Solution().postorderTraversal(root)); \
    } while(0)

    TEST(new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL)));
    TEST(new TreeNode(1, new TreeNode(2), new TreeNode(3)));
    TEST(new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                         new TreeNode(5, new TreeNode(6), new TreeNode(7))));
    return 0;
}
