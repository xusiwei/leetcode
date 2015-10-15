/*
copyright xu(xusiwei1236@163.com), all right reserved.

Unique Binary Search Trees II
==============================

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
1:
    1

2:
root    1       2
        1       2
         \     /
          2   1

3:
root    1       1       2       3       3
        1       1       2       3       3
         \       \     / \     /       /
          2       3   1   3   1       2
           \     /             \     /
            3   2               2   1

4:
  root  1           
        1           1              1           1           1
         \           \            /           /           /
          2           2          3           4           4
           \           \        / \         /           /
            3           4      2   4       2           3
             \         /                    \         /
              4       3                      3       2
  root  2
        2               2
       / \             / \
      1   3           1  4
           \            /
            4          3
  root  3
        3               3
       / \             / \
      1   4           2   4
       \             /
        2           1
  root  4
        4               4           4           4           4
       /               /           /           /           /
      1               1           2           3           3
       \               \         / \         /           /
        2               3       1   3       2           1
         \             /                   /             \
          3           2                   1               2
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
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int low, int high) {
        vector<TreeNode*> vtree;
        
        if(low > high) {
            vtree.push_back(NULL);
            return vtree;
        }
        if(low == high) {
            vtree.push_back(new TreeNode(low));
            return vtree;
        }
        
        for(int i = low; i <= high; i++) {
            vector<TreeNode*> vleft = generateTrees(low, i-1);
            vector<TreeNode*> vright = generateTrees(i+1, high);
            for(int j = 0; j < vleft.size(); j++) {
                for(int k = 0; k < vright.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = vleft[j];
                    root->right = vright[k];
                    vtree.push_back(root);
                }
            }
        }
        return vtree;
    }
};

void printTree(TreeNode* root)
{
    if(root == NULL) {
        printf("# ");
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char* argv[])
{
    int n = 4;

    if(argc > 1) {
        n = atoi(argv[1]);
    }
    
    vector<TreeNode*> trees = Solution().generateTrees(n);
    for(int i = 0; i < trees.size(); i++) {
        printTree(trees[i]);
        printf("\n");
    }
    return 0;
}
