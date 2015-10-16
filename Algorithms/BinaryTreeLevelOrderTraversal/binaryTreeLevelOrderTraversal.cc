/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Level Order Traversal
==================================

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
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
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > result;
		if(root == NULL) return result;
		
        deque<TreeNode*> queue;
		TreeNode* last = root; // last node of current level.
		int level = 0; // current level.
		
		queue.push_back(root);
		result.push_back(vector<int>()); // 1st level buffer.
		while(!queue.empty()) {
			TreeNode *node = queue.front();
			queue.pop_front();
			
			result[level].push_back(node->val);
			if(node->left) queue.push_back(node->left);
			if(node->right) queue.push_back(node->right);
			
			if(node == last) {
				level++;
				last = queue.back();
				result.push_back(vector<int>()); 
			}
		}
		result.pop_back();
		return result;
    }
};
