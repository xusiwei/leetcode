/*
copyright xu(xusiwei1236@163.com), all right reserved.

 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
*/

#include <iostream>

using namespace std;

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
    static ListNode* insertAfterAndGetNext(ListNode* prev, ListNode* node) {
        ListNode* nx = node->next;
        node->next = prev->next;
        prev->next = node;
        return nx;
    }

public:
    ListNode *swapPairs(ListNode *head) {
        if(NULL == head || NULL == head->next) return head;
        
        ListNode fake(0), *last = &fake;
        for(ListNode* p = head; p; ) {
            p = insertAfterAndGetNext(last, p);
            if(!p) break;
            p = insertAfterAndGetNext(last, p);
            last = last->next->next;
        }
        return fake.next;
    }
};


#ifdef TEST
#define ARRAYSIZE(a) sizeof(a)/sizeof((a)[0])
#define FUNC_TRACE cout << __func__ << "\n";
// #define FUNC_TRACE 

int printList(ListNode* head)
{FUNC_TRACE
    int count = 0;
    for(; head; head = head->next) {
        cout << head->val << (head->next ? "->" : ".\n");
        count++;
    }
    return count;
}

#define PRINTLIST(list) do { cout << #list << ":\n"; int count = printList(list); cout << "total: " << count << "\n"; } while(0)

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

int main()
{
    int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    // int ia[] = { 1 };
    // int ia[] = {  };
    
    ListNode* L = array2List(ia, ARRAYSIZE(ia)); PRINTLIST(L);

    Solution s;
    PRINTLIST(s.swapPairs(L));
    return 0;
}

#endif