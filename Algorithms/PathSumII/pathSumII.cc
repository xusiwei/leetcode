/*
copyright xu(xusiwei1236@163.com), all right reserved.

Path Sum II
============

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

*/
#include <stdio.h>
#include <assert.h>
#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    void pathSumHelper(vector<vector<int> >& out, int sum, TreeNode* root, vector<int>& path, int curr) {
        if (root == NULL) return ;
        
        curr += root->val;
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL) { // leaf node
             if (curr == sum) {
                 out.push_back(path);
             }
        } else {
            pathSumHelper(out, sum, root->left, path, curr);
            pathSumHelper(out, sum, root->right, path, curr);
        }
        path.pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int> > result;
        pathSumHelper(result, sum, root, path, 0);
        return result;
    }
};

string serialize(TreeNode* root);
TreeNode* deserialize(string str);
template <class Matrix>
void printMatrix(Matrix mat);


int main(int argc, char* argv[])
{
/*
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
*/
    TreeNode* root = deserialize("{5,4,8,11,#,13,4,7,2,#,#,5,1}");
    cout << serialize(root) << endl;
    printMatrix(Solution().pathSum(root, 22));
    return 0;
}

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

string serialize(TreeNode* root) {
    string result = "{";
    deque<TreeNode*> que;
    
    que.push_back(root);
    while( !que.empty() ) {
        TreeNode* n = que.front(); que.pop_front();
        if(n) {
            char buf[16] = {0};
            sprintf(buf, "%d", n->val);
            result += buf;
            que.push_back(n->left);
            que.push_back(n->right);
        }
        else {
            result += '#';
        }
        result += (que.empty() ? '}' : ',');
    }
#ifndef NTRIM
    if(result.length() > 5) { // trim tail #.
        // {1,#,#} => {1}, {2,1,3,#,#,#,#} => {2,1,3}.
        int idx = result.length() - 2;
        while(result[idx] == '#') idx -= 2;
        result[++idx] = '}';
        result.resize(++idx);
    }
#endif // NTRIM
    return result;
}

template <class Matrix>
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << ",";
        }
        cout << "\n";
    }
    cout << endl;
}


