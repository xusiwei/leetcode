/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Zigzag Level Order Traversal
=========================================

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

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
#include <deque>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* lst, TreeNode* rst) : val(x), left(lst), right(rst) {}
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
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == NULL) return result;

        int level = 0;
        deque<TreeNode*> queue;
        TreeNode *last = root;
        
        queue.push_back(root);
        result.push_back(vector<int>());
        while(!queue.empty()) {
            TreeNode *p = queue.front();
            queue.pop_front();
            
            result[level].insert(level & 1 ? result[level].begin() : result[level].end(), p->val);
            if(p->left) queue.push_back(p->left);
            if(p->right) queue.push_back(p->right);
            
            if(p == last) {
                level++;
                last = queue.back();
                result.push_back(vector<int>());
            }
        }
        result.pop_back();
        return result;        
    }
};

int main(int argc, char* argv[])
{
    TreeNode *root = new TreeNode(3, 
                        new TreeNode(9),
                        new TreeNode(20, 
                            new TreeNode(15),
                            new TreeNode(7)));
    vector<vector<int> > vv = Solution().zigzagLevelOrder(root);
    for(int i = 0; i < vv.size(); i++) {
        for(int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
