/*
copyright xu(xusiwei1236@163.com), all right reserved.

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2; // iterator
        ListNode fake(0), *tail = &fake; // result list head and tail.
        
        while(p && q) {
            if(p->val >= q->val) std::swap(p, q);
            tail->next = p;
            tail = p;
            p = p->next;
        }
        
        tail->next = p ? p : q;
        return fake.next;
    }
};