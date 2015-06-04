/*
copyright xu(xusiwei1236@163.com), all right reserved.

Sort a linked list using insertion sort.
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode fake = {0, 0}, *p;
    if(!head || !head->next) return head;
    for(p = head; p; ) {
        struct ListNode* n = p->next, *q;
        
        // find insertion point.
        for(q = &fake; q->next; q = q->next) {
            if(q->next->val >= p->val) break;
        }
        
        // insert p after q.
        p->next = q->next;
        q->next = p;
        
        p = n;
    }
    return fake.next;    
}


#ifdef TEST
#define ARRAYSIZE(a) sizeof(a)/sizeof((a)[0])
#define FUNC_TRACE puts(__func__);
// #define FUNC_TRACE 

typedef struct ListNode ListNode;
int printList(ListNode* head)
{FUNC_TRACE
    int count = 0;
    for(; head; head = head->next) {
        printf("%d%s", head->val, head->next ? "->" : ".\n");
        count++;
    }
    return count;
}

#define PRINTLIST(list) do { puts(#list); int count = printList(list); printf("total: %d\n", count); } while(0)

ListNode* array2List(int array[], int length)
{FUNC_TRACE
    int i;
    ListNode* head = NULL, *last = NULL;
    for(i=0; i<length; ++i) {
        ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
        temp->val = array[i];
        if(!head) head = temp;
        if(last) {
            last->next = temp;
        }
        last = temp;
    }
    return head;
}

int main()
{
    int ia[] = { 5, 6, 7, 8, 9, 1, 2, 3, 4, 10, 11 };
    // int ia[] = { 1 };
    // int ia[] = { 1, 1 };
    
    ListNode* L = array2List(ia, ARRAYSIZE(ia)); PRINTLIST(L);

    PRINTLIST(insertionSortList(L));
    return 0;
}

#endif
