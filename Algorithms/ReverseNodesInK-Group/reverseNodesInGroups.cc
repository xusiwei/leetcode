/*
copyright xu(xusiwei1236@163.com), all right reserved.

Reverse Nodes in k-Group
===========================

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    static void reorderAddTail(ListNode* ph, ListNode* beg, ListNode* end) {
        for(ListNode* p = beg; p != end; ) {
            ListNode* next = p->next;
            // cout << "add " << p->val << " after " << ph->val << endl;
            // insert after ph.
            p->next = ph->next;
            ph->next = p;
            
            p = next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || 1==k) return head;
        ListNode hint(0), *pgh = &hint, *beg = NULL;
        
        int count = 0;
        for(ListNode* p = head; p; ) {
            ListNode* next = p->next;
            const int i = ++count % k;
            // cout << "No. " << i << ", " << count << ": " << p->val << endl;
            if(i == 1) {
                beg = p;
            }
            else if(i == 0) {
                reorderAddTail(pgh, beg, p->next);
                pgh = beg;
                beg = NULL;
            }
            p = next;
        }
        
        if(beg) pgh->next = beg;
        return hint.next;
    }
};

#ifdef TEST
#define ARRAYSIZE(a) sizeof(a)/sizeof((a)[0])
// #define FUNC_TRACE cout << __func__ << "\n";
#define FUNC_TRACE 

int printList(ListNode* head)
{FUNC_TRACE
    int count = 0;
    while(head) {
        // printf("%d%s", head->val, head->next ? "->" : ".\n");
        cout << head->val << (head->next ? "->" : ".\n");
        head = head->next;
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

int main()
{
    // int ia[] = { 1,2,3,4,5,6 }, k = 3;
    // int ia[] = { 1 }, k = 1;
    int ia[] = { 1,2,3}, k = 2;
    
    ListNode* L = array2List(ia, ARRAYSIZE(ia)); PRINTLIST(L);
    
    ListNode* res = Solution().reverseKGroup(L, k); PRINTLIST(res);
    return 0;
}

#endif
