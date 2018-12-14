/*
Find Duplicate Subtrees
=======================

Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
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
    unordered_map<string, int> dict;

    struct Order {
        string in;
        string pre;
    };
    unordered_map<TreeNode*, Order> order;

    string preorderString(TreeNode* root) {
        if (root == NULL) {
            return order[root].pre = "#";
        }
        Order& t = order[root];
        if (root->left == NULL && root->right == NULL) {
            t.pre = to_string(root->val);
        } else {
            t.pre = to_string(root->val) + " " + preorderString(root->left) + " " + preorderString(root->right);
        }
        return t.pre;
    }


    string inorderString(TreeNode* root, vector<TreeNode*>& result) {
        if (root == NULL) {
            return order[root].in = "#";
        }
        Order& t = order[root];
        if (root->left == NULL && root->right == NULL) {
            t.in = to_string(root->val);
        } else {
            t.in = inorderString(root->left, result) + " " + to_string(root->val) + " " + inorderString(root->right, result);
        }

        auto str = t.in + "," + t.pre;
        if (++dict[str] == 2) {
            result.push_back(root);
        }

        return t.in;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        dict.clear();
        order.clear();
        preorderString(root);
        inorderString(root, result);
        return result;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), NULL),
                                     new TreeNode(3, new TreeNode(2, new TreeNode(4), NULL),
                                                     new TreeNode(4)));
    auto v = Solution().findDuplicateSubtrees(root);
    for (auto& n: v) {
        cout << n->val << endl;
    }
    return 0;
}


