/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Preorder Traversal
===============================

Given a binary tree, return the preorder traversal of its nodes' values.


For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3



return [1,2,3].


Note: Recursive solution is trivial, could you do it iteratively?
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

class Solution {
public:

#ifdef RECURSIVE
    void preorderTraversalHelper(vector<int>& result, TreeNode* root) {
        if (root == NULL) return;
        result.push_back(root->val);
        preorderTraversalHelper(result, root->left);
        preorderTraversalHelper(result, root->right);
    }

    // recursive
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversalHelper(result, root);
        return result;
    }

#else // RECURSIVE

    // iterative
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        vector<TreeNode*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            TreeNode* p = stack.back();
            stack.pop_back();
            if (p != NULL) {
                result.push_back(p->val);
                stack.push_back(p->right);
                stack.push_back(p->left);
            }
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
        printVector(Solution().preorderTraversal(root)); \
    } while(0)

    TEST(new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL)));
    TEST(new TreeNode(1, new TreeNode(2), new TreeNode(3)));
    TEST(new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                         new TreeNode(5, new TreeNode(6), new TreeNode(7))));

    return 0;
}
