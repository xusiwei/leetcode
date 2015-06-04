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