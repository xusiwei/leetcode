/*
copyright xu(xusiwei1236@163.com), all right reserved.

Reorder List
=============

Given a singly linked list L: L0 -> L1 -> ... -> Ln-1 -> Ln,
reorder it to: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static int getLength(struct ListNode* head) {
    int count = 0;
    for(; head; head = head->next) {
        count++;
    }
    return count;
}

static struct ListNode* getNode(struct ListNode* head, int num) {
    int count = 0;
    for(; head; head = head->next) {
        if(count++ == num) return head;
    }
    return NULL;
}

void reorderList(struct ListNode* head) {
    int len;
    struct ListNode *tail, *last, *p, *q, fake = {0, 0};
    
    if(!head || !head->next) return;
    len = getLength(head);
    tail = getNode(head, len/2 - (1 - len&1)); // tail of 1st part.
    last = tail->next; // head of 2nd part.
    tail->next = NULL; // cut down 1st part.
    
    // reverse last part.
    for(p = last; p; ) {
        struct ListNode* n = p->next;
        p->next = fake.next;
        fake.next = p;
        p = n;
    }
    
    // merge two parts.
    for(p = fake.next, q = head; p && q; ) {
        struct ListNode *pn = p->next, *qn = q->next;
        p->next = q->next;
        q->next = p;
        p = pn; q = qn;
    }
}
