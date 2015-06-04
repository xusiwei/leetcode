/*
copyright xu(xusiwei1236@163.com), all right reserved.

Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nset;
        while( head ) {
            unordered_set<ListNode*>::iterator it = nset.find(head);
            if( it != nset.end() ) {
                return *it;
            }
            nset.insert(head);
            head = head->next;
        }
        return NULL;
    }
};