/*
copyright xu(xusiwei1236@163.com), all right reserved.

Reverse Linked List
====================

Reverse a singly linked list.

click to show more hints.
Hint:

A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    ListNode* reverseList(ListNode* head) {
        ListNode fake(0);
        while(head) {
            ListNode *next = head->next;
            head->next = fake.next;
            fake.next = head;
            head = next;
        }
        return fake.next;
    }
};
