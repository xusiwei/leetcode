/*
copyright xu(xusiwei1236@163.com), all right reserved.

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if( head == NULL || head->next == NULL) return head;
        
        // 1. count nodes. 
        int cnt=0;
        ListNode *cur = head, *last = NULL;
        while(cur) {
            ++cnt;
            last = cur;
            cur = cur->next;
        }
        
        k %= cnt;
        if( k == 0 ) return head;
        
        // 2. get the prev node of new head.
        ListNode *prev = head;
        for(int i=1;  i<cnt-k; ++i) {
            prev = prev->next;
        }
        
        last->next = head;
        head = prev->next;
        prev->next = NULL;
        
        return head;
    }
};