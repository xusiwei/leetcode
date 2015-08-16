/*
copyright xu(xusiwei1236@163.com), all right reserved.

Add Two Numbers
================

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int inc = 0;
        ListNode hint(0), *last = &hint;
        while(l1 && l2) {
            int sum = l1->val + l2->val + inc;
            ListNode* temp = new ListNode(sum % 10);
            inc = sum / 10;
            
            last->next = temp;
            last = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l2) l1 = l2;
        while(l1) {
            int sum = l1->val + inc;
            last->next = new ListNode(sum % 10);
            inc = sum / 10;
            
            last = last->next;
            l1 = l1->next;
        }
        if(inc) last->next = new ListNode(inc);
        return hint.next;
    }
};

#ifdef TEST
#define ARRAYSIZE(a) sizeof(a)/sizeof((a)[0])
#define FUNC_TRACE printf("%s\n", __func__);

ListNode* array2List(int array[], int length)
{FUNC_TRACE
    ListNode* head = NULL, *last = NULL;
    for(int i=0; i<length; ++i) {
        ListNode* temp = new ListNode(array[i]);
        if(!head) head = temp;
        if(last) {
            last->next = temp;
        }
        last = temp;
    }
    return head;
}

void printList(ListNode* head) {FUNC_TRACE
    while(head) {
        printf("%d%s", head->val, head->next ? "->" : ".\n");
        head = head->next;
    }
}

int main()
{
    int a1[] = { 3, 7 };
    int a2[] = { 9, 2 };
    
    ListNode* L1 = array2List(a1, ARRAYSIZE(a1)); printList(L1);
    ListNode* L2 = array2List(a2, ARRAYSIZE(a2)); printList(L2);
    
    ListNode* L3 = Solution().addTwoNumbers(L1, L2);
    printList(L3);
    
    return 0;
}
#endif
