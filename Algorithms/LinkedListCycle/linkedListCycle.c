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
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
    struct ListNode *fast = head, *slow = head;
    while(slow && fast) {
        slow = slow->next;
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        if(fast == slow) return true;
    }
    return false;
}
