/*
copyright xu(xusiwei1236@163.com), all right reserved.

Populating Next Right Pointers in Each Node
============================================

 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL


*/
#include <queue>
#include <stdio.h>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    TreeLinkNode(int x, TreeLinkNode* L, TreeLinkNode* R) 
        : val(x), left(L), right(R), next(NULL) {}
};


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        queue<TreeLinkNode*> q;
        TreeLinkNode *prev, *last;
        prev = last = root;
        
        q.push(root);
        while(!q.empty()) {
            TreeLinkNode* p = q.front();
            q.pop();

            prev->next = p;
            if(p->left ) q.push(p->left);
            if(p->right) q.push(p->right);

            if(p == last) { // meets last of current level
                // now, q contains all nodes of next level
                last = q.back();
                p->next = NULL; // cut down.
                prev = q.front();
            }
            else {
                prev = p;
            }
        }
    }
};

void printLinkTree(TreeLinkNode* root) {
    TreeLinkNode *head = root, *p = root;
    while(p) {
        printf("%d%s", p->val, (p->next) ? "->" : "\n");
        if(p->next != NULL) {
            p = p->next;
        }
        else {
            head = head->left;
            p = head;
        }
    }
}

int main(int argc, char* argv[])
{
    TreeLinkNode* root = new TreeLinkNode(1,
                            new TreeLinkNode(2,
                                new TreeLinkNode(4),
                                new TreeLinkNode(5)),
                            new TreeLinkNode(3,
                                new TreeLinkNode(6),
                                new TreeLinkNode(7)));
    Solution().connect(root);
    printLinkTree(root);
    return 0;
}
