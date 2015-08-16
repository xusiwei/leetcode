/*
copyright xu(xusiwei1236@163.com), all right reserved.

Remove Nth Node From End of List
=================================

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        for(ListNode* p = head;  p; p = p->next) {
            count++;
        }
        
        ListNode hint(0), *prev = &hint;
        hint.next = head;
        
        for(ListNode *p = head; p; ) {
            ListNode *next = p->next;
            if(count-- == n) {
                prev->next = next;
                delete p;
                break;
            }
            prev = p;
            p = next;
        }
        
        return hint.next;
    }
};
