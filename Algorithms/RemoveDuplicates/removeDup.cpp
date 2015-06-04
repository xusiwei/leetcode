/*
copyright xu(xusiwei1236@163.com), all right reserved.

Remove Duplicates from Sorted List
====================================

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Hide Tags Linked List
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(NULL == head) return NULL;
        ListNode* prev = head;
        ListNode* cur = head->next;
        for(  ; cur; cur = cur->next) {
            if(cur->val == prev->val) {
                prev->next = cur->next;
                delete cur;
            }
            else prev = cur;
        }
        return head;
    }
};