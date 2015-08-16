/*
copyright xu(xusiwei1236@163.com), all right reserved.

Convert Sorted List to Binary Search Tree
==========================================

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    static int getLength(ListNode* head) {
        int count=0;
        for(ListNode* p = head; p; p = p->next) {
            count++;
        }
        return count;
    }
    
    static ListNode* getNode(ListNode* head, int num) {
        int count=0;
        for(ListNode* p = head; p; p = p->next) {
            if(count++ == num) return p;
        }
        return NULL;
    }
    
    static TreeNode* makeTree(ListNode* beg, int len) {
        if(len == 0) return NULL;
        if(len == 1) return new TreeNode(beg->val);

        ListNode* half = getNode(beg, len/2);
        TreeNode* root = new TreeNode(half->val);
        root->left = makeTree(beg, len/2);
        root->right = makeTree(half->next, len - len/2 - 1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return makeTree(head, getLength(head));
    }
};


#ifdef TEST
#define ARRAYSIZE(a) sizeof(a)/sizeof((a)[0])
#define FUNC_TRACE cout << __func__ << "\n";
// #define FUNC_TRACE 

int printList(ListNode* head)
{FUNC_TRACE
    int count = 0;
    for(; head; head = head->next) {
        cout << head->val << (head->next ? "->" : ".\n");
        count++;
    }
    return count;
}

#define PRINTLIST(list) do { cout << #list << ":\n"; int count = printList(list); cout << "total: " << count << "\n"; } while(0)

ListNode* array2List(int array[], int length)
{FUNC_TRACE
    ListNode* head = NULL, *last = NULL;
    for(int i=0; i<length; ++i) {
        ListNode* temp = new ListNode(array[i]);
        if(!head) head = temp;
        if(last) {
            last->next = temp;
        }
        last = temp;
    }
    return head;
}

void printTree(TreeNode* root)
{
    if(!root) return;
    
    printTree(root->left);
    cout << root->val << " at " << root << endl;
    if(root->left) cout << " ->" << root->left->val << " at " << root->left << endl;
    if(root->right) cout << " ->" << root->right->val << " at " << root->right << endl;
    
    printTree(root->right);
}

int main()
{
    int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // int ia[] = { 1 };
    // int ia[] = {  };
    
    ListNode* L = array2List(ia, ARRAYSIZE(ia)); PRINTLIST(L);

    Solution s;
    TreeNode* root = s.sortedListToBST(L);
    printTree(root);
    return 0;
}

#endif
