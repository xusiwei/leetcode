/*
Binary Tree Longest Consecutive Sequence II
============================================

Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this ends can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the ends [1,2,4,3] is not valid. On the other hand, the ends can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive ends is [1, 2] or [2, 1].
Example 2:
Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive ends is [1, 2, 3] or [3, 2, 1].
Note: All the values of tree nodes are in the range of [-1e7, 1e7].
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <deque>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

#ifdef DEBUG
#define VERBOSE(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#else
#define VERBOSE(...)
#endif

struct OnExit {
    OnExit(function<void(void)> f)
        : callback_(f)
    {
    }
#ifdef DEBUG
    ~OnExit()
    {
        callback_();
    }
#endif
private:
    function<void(void)> callback_;
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
class Solution
{
    map<TreeNode*, list<TreeNode*> > dict;

    list<TreeNode*>& endwith(TreeNode* root)
    {
        if (dict.find(root) != dict.end()) {
            return dict[root];
        }

        OnExit _([&]() {
            int size = -1;
            if (dict.find(root) != dict.end()) {
                size = (int)dict[root].size();
            }
            printf("OnExit %p> %d: %d\n", root, root ? root->val : -1, size);
        });

        if (root == NULL) {
            dict[root] = {};
            return dict[root];
        }

        TreeNode* lchild = root->left;
        TreeNode* rchild = root->right;
        if (lchild == NULL && rchild == NULL) {
            dict[root] = { root };
            return dict[root];
        }

        auto lpath = endwith(lchild);
        auto rpath = endwith(rchild);
        list<TreeNode*> result = { root };

#define EXTEND(path, child)                                            \
    if (path.size() > 0) {                                             \
        if (path.back() == child && child->val + 1 == root->val) {     \
            path.push_back(root);                                      \
            VERBOSE("[...%d] append %d\n", child->val, root->val);     \
        }                                                              \
        if (path.front() == child && root->val + 1 == child->val) {    \
            path.push_front(root);                                     \
            VERBOSE("prepend %d to [%d...]\n", root->val, child->val); \
        }                                                              \
    }

        VERBOSE("check for %d, %zd %zd\n", root->val, lpath.size(), rpath.size());
        EXTEND(lpath, lchild);
        EXTEND(rpath, rchild);

        dict[root] = lpath.size() > rpath.size() ? lpath : rpath;
        dict[root] = dict[root].size() > result.size() ? dict[root] : result;
        return dict[root];
    }

    int lcp_recursive(TreeNode* root)
    {
        if (root == NULL) return 0;

        auto lchild = root->left;
        auto rchild = root->right;
        if (lchild == NULL && rchild == NULL) {
            return 1;
        }

        int result = (int)endwith(root).size();
        result = max(result, lcp_recursive(lchild));
        result = max(result, lcp_recursive(rchild));

        auto lpath = endwith(lchild);
        auto rpath = endwith(rchild);
        if (lpath.size() > 0 && rpath.size() > 0
            && lchild == lpath.back() && lchild->val + 1 == root->val
            && rchild == rpath.front() && root->val + 1 == rchild->val) {
            result = max(result, (int)lpath.size() + 1 + (int)rpath.size());
        }
        return result;
    }

public:
    int longestConsecutive(TreeNode* root)
    {
        dict.clear();
        return lcp_recursive(root);
    }
};

// #include <stdlib.h>
// #include <assert.h>
// #include <deque>
TreeNode* deserialize(string str)
{
    TreeNode* root = NULL;
    int len = str.length();

    assert(str[0] == '{' && str[len - 1] == '}');

    deque<TreeNode**> que;
    que.push_back(&root);

    len--;
    int tok = 1;
    while (tok < len) {
        TreeNode** writer = que.front();
        que.pop_front();
        TreeNode* node = NULL;
        if (str[tok] != '#') {
            char* end = &str[tok];
            long val = strtol(&str[tok], &end, 10);
            tok += end - &str[tok];
            // trace("took %ld\n", val);
            node = new TreeNode(val);
            que.push_back(&(node->left));
            que.push_back(&(node->right));
        } else { // '#'
            tok++;
        }
        tok++; // skip ','
        *writer = node;
    }
    return root;
}

void printTree(TreeNode* root)
{
    vector<TreeNode*> s;

    if (root) s.push_back(root);

    while (s.size()) {
        TreeNode* p = s.back();
        s.pop_back();
        if (p->left) {
            s.push_back(p->left);
            printf("\t%d -> %d;\n", p->val, p->left->val);
        }
        if (p->right) {
            s.push_back(p->right);
            printf("\t%d -> %d;\n", p->val, p->right->val);
        }
    }
}

int main(int argc, char* argv[])
{
    string s = "{3,2,4,1,#,5}";
    if (argc > 1) s = argv[1];
    printf("// tree: %s\n", s.c_str());

    TreeNode* root = deserialize(s);
    auto LCP = Solution().longestConsecutive(root);

    printf("digraph tree_%p {\n", root);
    printTree(root);
    printf("\"LCP: %d\"[shape=box];\n", LCP);
    printf("}\n");
    printf("// %d\n", LCP);
    return 0;
}

// vim: set ts=4 sw=4 et
