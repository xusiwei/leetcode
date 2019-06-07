/*
copyright xu(xusiwei1236@163.com), all right reserved.

Lowest Common Ancestor Of A Binary Tree
=======================================

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]




Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.

*/
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <unordered_set>

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
    size_t getPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* p) {
        if (!root || !p) return 0;

        path.push_back(root); // trying
        // printf("trying %d, %zu\n", root->val, path.size());
        if (p == root) { // found ?
            return path.size();
        }

        // for each children
        TreeNode* children[]{root->left, root->right};
        for (TreeNode* child: children) {
            if (getPath(child, path, p)) return path.size();
        }
        // printf("backtrack %d, %zu\n", path.back()->val, path.size());
        path.pop_back(); // backtrack
        return 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a, b;
        size_t M = getPath(root, a, p); // printf("getPath %d, %zu\n", p ? p->val : -1, M);
        size_t N = getPath(root, b, q); // printf("getPath %d, %zu\n", q ? q->val : -1, N);
        TreeNode* last = root;
        for (size_t i = 0, T = std::min(M, N); i < T; i++) {
            if (a[i] != b[i]) break;
            last = a[i];
        }
        return last;
    }
};

class Solution2 {
    int count;
    TreeNode* p;
    TreeNode* q;
    vector<TreeNode*> path;
    vector<TreeNode*> a;
    vector<TreeNode*> b;

    bool getPath(TreeNode* root) {
        if (!root || !p) return false;

        path.push_back(root); // trying
        // printf("trying %d, %zu\n", root->val, path.size());
        if (root == p) {
            a = path; if (++count == 2) return true;
        }
        if (root == q) {
            b = path; if (++count == 2) return true;
        }

        // for each children
        TreeNode* children[]{root->left, root->right};
        for (TreeNode* child: children) {
            if (getPath(child)) return true;
        }
        // printf("backtrack %d, %zu\n", path.back()->val, path.size());
        path.pop_back(); // backtrack
        return 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        count = 0;
        a.clear();
        b.clear();
        path.clear();
        this->p = p;
        this->q = q;

        getPath(root);
        TreeNode* last = root;
        for (size_t i = 0, T = std::min(a.size(), b.size()); i < T; i++) {
            if (a[i] != b[i]) break;
            last = a[i];
        }
        return last;
    }
};

class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> s{root};
        while (s.size()) {
            TreeNode* top = s.back(); s.pop_back();
            if (top) {
                if (top->right) {
                    parent[top->right] = top;
                    s.push_back(top->right);
                }
                if (top->left) {
                    parent[top->left] = top;
                    s.push_back(top->left);
                }
            }
        }

        // get nodes on the path from p to root(P2R)
        unordered_set<TreeNode*> p2r; // node set
        TreeNode* t = p;
        while (t) {
            p2r.insert(t);
            auto it = parent.find(t);
            t = it != parent.end() ? it->second : nullptr;
        }

        // travel on the path from q to root
        // check if current node on the P2R or not?
        t = q;
        while (t) {
            if (p2r.count(t)) {
                return t;
            }
            auto it = parent.find(t);
            t = it != parent.end() ? it->second : nullptr;
        }
        return nullptr;
    }
};

void printTree(TreeNode* root, int level=0)
{
    if (!root) {
        return;
    }
    printf("%2d", root->val);

    if (root->left) {
        printf("->");
        printTree(root->left, level+1);
    }
    if (root->right) {
        printf("%s->", string(4*level+2, ' ').c_str());
        printTree(root->right, level+1);
    }
    if (!root->left && !root->right) printf("\n"); // it's leaf node!
}

void deleteTree(TreeNode* root)
{
    if (!root) return;
    if (root->left) delete root->left;
    if (root->right) delete root->right;
    delete root;
}

using placeholders::_1;
using placeholders::_2;
using placeholders::_3;

int main(int argc, char* argv[])
{
    TreeNode* root = nullptr;
    TreeNode* p = nullptr;
    TreeNode* q = nullptr;
    root = new TreeNode(3, new TreeNode(5, new TreeNode(6),
                                            new TreeNode(2, new TreeNode(7),
                                                            new TreeNode(4))),
                            new TreeNode(1, new TreeNode(0),
                                            new TreeNode(8)));
    printTree(root);
    auto get_node = [](TreeNode* root, int x) -> TreeNode* {
        vector<TreeNode*> s{root};
        while (s.size()) {
            TreeNode* top = s.back(); s.pop_back();
            if (top->val == x) return top;
            if (top) {
                if (top->right) s.push_back(top->right);
                if (top->left) s.push_back(top->left);
            }
        }
        return nullptr;
    };
    p = get_node(root, argc > 1 ? atoi(argv[1]) : 6);
    q = get_node(root, argc > 2 ? atoi(argv[2]) : 8);

    cout << "p: " << p->val << endl;
    cout << "q: " << q->val << endl;

    function<TreeNode*(void)> solve[]{
        [&](){ return Solution().lowestCommonAncestor(root, p, q); },
        [&](){ return Solution2().lowestCommonAncestor(root, p, q); },
        [&](){ return Solution3().lowestCommonAncestor(root, p, q); },
    };
    TreeNode* lca = solve[rand() % sizeof(solve)/sizeof(solve[0])]();
    if (lca) {
        cout << "LCA: " << lca->val << endl;
    } else {
        cout << "LCA: not found!" << endl;
    }
    deleteTree(root);
    return 0;
}
