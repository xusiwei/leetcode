/*
copyright xu(xusiwei1236@163.com), all right reserved.

Validate Binary Search Tree
============================

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int gTraceCounter = 0;
#ifdef TRACE
#define trace printf
#define CT trace("%s: %p, %d, %d\n", __FUNCTION__, this, this->val, gTraceCounter++); // ctor trace
#define DT trace("%s: %p, %d, %d\n", __FUNCTION__, this, this->val, --gTraceCounter); // dtor trace
#else // TRACE
#define trace
#define CT
#define DT
#endif // TRACE

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {CT}
    TreeNode(int x, TreeNode* lst, TreeNode* rst = NULL) : val(x), left(lst), right(rst) {CT}
    ~TreeNode() {DT}
};

#ifdef RECUSIVE
// recusive, range based sulotion.
class Solution {
    int minCount, maxCount;
public:

    bool isValid(TreeNode* root, int low, int high) {
        if(root == NULL) return true;
        
        // side cases.
        if(root->val == INT_MIN && low == INT_MIN) return root->left  == NULL && ++minCount == 1 && isValid(root->right, root->val, high);
        if(root->val == INT_MAX && high == INT_MAX) return root->right == NULL && ++maxCount == 1 && isValid(root->left, low, root->val);
        
        if(root->val <= low || root->val >= high) {
            return false;
        }
        return isValid(root->left, low, root->val) && isValid(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        minCount = maxCount = 0;
        return isValid(root, INT_MIN, INT_MAX);
    }
};
#else // RECUSIVE
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> stack;
        TreeNode* last = NULL;
        
        // inorder sequence of a BST is ordered.
        while(stack.size() > 0 || root != NULL) {
            if(root != NULL) {
                stack.push_back(root);
                root = root->left;
            }
            else {
                root = stack.back(); stack.pop_back();
                // visitor.
                if(last != NULL && last->val >= root->val) {
                    return false;
                }
                last = root;
                root = root->right;
            }
        }
        return true;
    }
};
#endif // RECUSIVE

void deleteTree(TreeNode* root) {
    if(root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
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

#define ARRAYSIZE(a) sizeof(a)/sizeof(a[0])

void testSerialize() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3, new TreeNode(4, NULL, new TreeNode(5))));
    cout << serialize(root) << endl;
    deleteTree(root);
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

void testDeserialze() {
    TreeNode* root = deserialize("{1,2,3,#,#,4,#,#,5}");
    cout << serialize(root) << endl;
    deleteTree(root);
}

int main(int argc, char* argv[])
{
    testSerialize();
    testDeserialze();
    
#define TEST(expr) \
    do{ TreeNode* root = expr; \
        cout << serialize(root) << ": " << Solution().isValidBST(root) << endl; \
        deleteTree(root); \
    } while(0)
    
    TEST( NULL );
    TEST( new TreeNode(1) );
    TEST( new TreeNode(1, new TreeNode(1)) );
    TEST( new TreeNode(2, new TreeNode(1)) );
    TEST( new TreeNode(1, new TreeNode(1), new TreeNode(1)) );
    TEST( new TreeNode(2, new TreeNode(1), new TreeNode(3)) );
    TEST( new TreeNode(1, new TreeNode(2), new TreeNode(3)) );
    
    TEST( new TreeNode(INT_MIN) );
    TEST( new TreeNode(INT_MAX) );
    TEST( new TreeNode(1, new TreeNode(INT_MAX)) );
    TEST( new TreeNode(INT_MAX, new TreeNode(1)) );
    TEST( new TreeNode(1, new TreeNode(INT_MIN)) );
    TEST( new TreeNode(INT_MIN, new TreeNode(1)) );
    TEST( new TreeNode(INT_MAX, new TreeNode(INT_MAX)) );
    TEST( new TreeNode(INT_MIN, new TreeNode(INT_MIN)) );
    TEST( new TreeNode(INT_MAX, new TreeNode(INT_MIN)) );
    TEST( new TreeNode(INT_MIN, NULL, new TreeNode(INT_MAX)) );
    
    TEST( new TreeNode(2, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(5))) );
    TEST( deserialize("{3,2,#,1,-2147483648}") );
    return 0;
}
