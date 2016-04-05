/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Right Side View
============================

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---



You should return [1, 3, 4].


Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) return result;
        
        TreeNode* last = root;
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()) {
            TreeNode* p = q.front(); q.pop();
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
            if (p == last) {
                result.push_back(p->val);
                last = q.back();
            }
        }
        return result;
    }
};

template <typename Vector>
void printVector(const Vector& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(5)),
                                     new TreeNode(3, NULL, new TreeNode(4)));
    printVector(Solution().rightSideView(root));
    return 0;
}
