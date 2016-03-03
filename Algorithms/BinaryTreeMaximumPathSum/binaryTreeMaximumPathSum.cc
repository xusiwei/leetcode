/*
copyright xu(xusiwei1236@163.com), all right reserved.

Binary Tree Maximum Path Sum
=============================

Given a binary tree, find the maximum path sum.


For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.


For example:
Given the below binary tree,

       1
      / \
     2   3



Return 6.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <deque>
#include <utility>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int result_;
public:
    // caculate path sum, which across current node
    int pathSumHelper(TreeNode* root) {
        if (root == NULL) return 0;
        int lsum = pathSumHelper(root->left);
        int rsum = pathSumHelper(root->right);
        result_ = max(result_, root->val + max(lsum, 0) + max(rsum, 0));
        return max(max(lsum, rsum), 0) + root->val;
        // return max(lsum, rsum) + root->val;  // path end with leaf node
    }
    
    int maxPathSum(TreeNode* root) {
        result_ = INT_MIN;
        pathSumHelper(root);
        return result_;
    }
};

// #include <stdlib.h>
// #include <assert.h>
// #include <deque>
TreeNode* deserialize(string str) {
    TreeNode* root = NULL;
    int len = str.length();
    
    assert(str[0] == '{' && str[len-1] == '}');

    deque<TreeNode**> que;
    que.push_back(&root);
    
    len--;
    int tok = 1;
    while( tok < len ) {
        TreeNode** writer = que.front(); que.pop_front();
        TreeNode* node = NULL;
        if(str[tok] != '#') {
            char* end = &str[tok];
            long val = strtol(&str[tok], &end, 10);
            tok += end - &str[tok];
            // trace("took %ld\n", val);
            node = new TreeNode(val);
            que.push_back(&(node->left));
            que.push_back(&(node->right));
        }
        else { // '#'
            tok++;
        }
        tok++; // skip ','
        *writer = node;
    }
    return root;
}

int main(int argc, char* argv[])
{
//     TreeNode* root = deserialize("{-1,2,3,4,5,6,7}");
//     TreeNode* root = deserialize("{5,4,8,11,#,13,4,7,2,#,#,#,1}");
    TreeNode* root = deserialize("{9,6,-3,#,#,-6,2,#,#,2,#,-6,-6,-6}");
    cout << Solution().maxPathSum(root) << endl;
    return 0;
}
