/*
copyright xu(xusiwei1236@163.com), all right reserved.

Lowest Common Ancestor Of A Binary Search Tree
==============================================

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]




Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.
*/

#include <assert.h>
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
    static size_t getPath4BST(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (!root || !p) return 0;

        path.push_back(root);
        if (p->val == root->val) {
            return 1;
        } else if (p->val < root->val) {
            return 1 + getPath4BST(root->left, p, path);
        } else {
            return 1 + getPath4BST(root->right, p, path);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        vector<TreeNode*> a, b;
        size_t m = getPath4BST(root, p, a);
        size_t n = getPath4BST(root, q, b);
        TreeNode* last = nullptr;
        for (size_t i = 0; i < min(m, n); i++) {
            if (a[i] != b[i]) break;
            last = a[i];
        }
        return last;
    }
};

void printTree(TreeNode* root, int level=0)
{
    if (!root) {
        return;
    }
    printf("%2d", root->val);

    if (root->left) {
        printf("->");
        printTree(root->left, level+1);
    }
    if (root->right) {
        printf("%s->", string(4*level+2, ' ').c_str());
        printTree(root->right, level+1);
    }
    if (!root->left && !root->right) printf("\n"); // it's leaf node!
}

void deleteTree(TreeNode* root)
{
    if (!root) return;
    if (root->left) delete root->left;
    if (root->right) delete root->right;
    delete root;
}

TreeNode* findNode(TreeNode* root, int x)
{
    vector<TreeNode*> s{root};
    TreeNode* t = nullptr;
    while (s.size()) {
        t = s.back(); s.pop_back();
        if (t->val == x) break;
        if (t) {
            if (t->right) s.push_back(t->right);
            if (t->left) s.push_back(t->left);
        }
    }
    return t;
}

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    TreeNode* p = nullptr;
    TreeNode* q = nullptr;
    root = new TreeNode(6, new TreeNode(2, new TreeNode(0),
                                            new TreeNode(4, new TreeNode(3),
                                                            new TreeNode(5))),
                            new TreeNode(8, new TreeNode(7),
                                            new TreeNode(9)));
    printTree(root);
    p = findNode(root, argc > 1 ? atoi(argv[1]) : 6);
    q = findNode(root, argc > 2 ? atoi(argv[2]) : 8);
    assert(p && q);

    cout << "p: " << p->val << endl;
    cout << "q: " << q->val << endl;

    TreeNode* lca = Solution().lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "LCA: " << lca->val << endl;
    } else {
        cout << "LCA: not found!" << endl;
    }
    deleteTree(root);
    return 0;
}
