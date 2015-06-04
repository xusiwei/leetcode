/*
copyright xu(xusiwei1236@163.com), all right reserved.

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 -> a2
                   \
                    c1 -> c2 -> c3
                   /
B:    b1 -> b2 -> b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* pA = headA, *pB = headB;
    int a = 0, b = 0;
    
    // [A1, A2, ... ..., Am, C1, C2, ..., Cn][B1, B2, ..., Bk, C1, C2, ..., Cn]
    // [B1, B2, ..., Bk, C1, C2, ..., Cn][A1, A2, ... ..., Am, C1, C2, ..., Cn]
    //                                                         ^same
    while(pA && pB) {
        if(pA == pB) return pA;
        pA = pA->next;
        pB = pB->next;
        if(pA == NULL && a++ == 0) pA = headB;
        if(pB == NULL && b++ == 0) pB = headA;
    }
    return NULL;    
}