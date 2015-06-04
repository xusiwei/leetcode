/*
copyright xu(xusiwei1236@163.com), all right reserved.

Partition List
=================

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode low(0), up(0);
        ListNode *lt = &low, *ut = &up;
        while(head) {
            ListNode* next = head->next;
            if(head->val < x) {
                lt->next = head;
                lt = head;
                lt->next = NULL;
            }
            else {
                ut->next = head;
                ut = head;
                ut->next = NULL;
            }
            head = next;
        }
        lt->next = up.next;
        return low.next;
    }
};