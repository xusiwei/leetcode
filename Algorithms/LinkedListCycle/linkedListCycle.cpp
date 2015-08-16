/*
copyright xu(xusiwei1236@163.com), all right reserved.

Linked List Cycle
==================

 Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nset;
        while( head ) {
            unordered_set<ListNode*>::iterator it = nset.find(head);
            if( it != nset.end() ) {
                return true;
            }
            nset.insert(head);
            head = head->next;
        }
        return false;
    }
};
