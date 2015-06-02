/*
copyright xu(xusiwei1236@163.com), all right reserved.

 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
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
    ListNode *swapPairs(ListNode *head) {
        if(NULL == head || NULL == head->next) return head;
        
        ListNode *res = head->next, *last = NULL;
        ListNode *prv = head, *cur = prv->next;
        while(cur && prv) {
            ListNode *nxt = cur->next;
            if(last) last->next = cur;
            cur->next = prv;
            prv->next = nxt;
            last = prv;
            if(NULL == nxt) break;
            prv = nxt;
            cur = nxt->next;
        }
        return res;
    }
};