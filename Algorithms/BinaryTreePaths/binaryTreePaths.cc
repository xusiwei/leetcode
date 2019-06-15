/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Paths
=================

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

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
    void traversal(TreeNode* root, vector<string>& result, string& path) {
        if (!root) return;
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }

        TreeNode* children[] = {root->left, root->right};
        for (TreeNode* child: children) {
            if (child) {
                auto size = path.size();
                path += "->";
                path += to_string(child->val);
                traversal(child, result, path);
                path.resize(size);
            }
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> result;
        if (root) {
            path = to_string(root->val);
            traversal(root, result, path);
        }
        return result;
    }
};
