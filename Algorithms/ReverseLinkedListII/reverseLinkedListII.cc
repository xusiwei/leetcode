/*
copyright xu(xusiwei1236@163.com), all right reserved.

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 \u2264 m \u2264 n \u2264 length of list. 
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
    static ListNode* getNode(ListNode* head, int num) {
        int count = 0;
        for(ListNode* p = head; p; p = p->next) {
            if(count++ == num) return p;
        }
        return NULL;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode fake(0);
        fake.next = head;
        
        ListNode* pom = getNode(&fake, m - 1); // prev of m
        ListNode* non = getNode(&fake, n + 1); // next of n
        
        ListNode* pm = pom->next;
        for(ListNode* p = pm; p != non; ) {
            ListNode* n = p->next;
            p->next = pom->next;
            pom->next = p;
            p = n;
        }
        pm->next = non;
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
    // int ia[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, m = 2, n = 4;
    int ia[] = { 3, 5 }, m = 1, n = 2;

    ListNode* L = array2List(ia, ARRAYSIZE(ia)); PRINTLIST(L);

    Solution s;
    PRINTLIST(s.reverseBetween(L, m, n));
    return 0;
}

#endif