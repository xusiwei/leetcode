/*
copyright xu(xusiwei1236@163.com), all right reserved.

Remove Linked List Elements
============================

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

#include <stdio.h>
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
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode hint(0), *prev = &hint, *curr = head;
        hint.next = head;
        while(curr) {
            ListNode *next = curr->next;
            if(curr->val == val) {
                // printf("found %d at %p -> %p\n", val, curr, next);
                prev->next = next;
                delete curr;
            }
            else prev = curr;
            curr = next;
        }
        return hint.next;
    }
};


#ifdef TEST
#define ARRAYSIZE(a) sizeof(a)/sizeof((a)[0])
// #define FUNC_TRACE cout << __func__ << "\n";
#define FUNC_TRACE 

int printList(ListNode* head)
{FUNC_TRACE
    int count = 0;
    while(head) {
        // printf("%d%s", head->val, head->next ? "->" : ".\n");
        cout << head->val << (head->next ? "->" : ".\n");
        head = head->next;
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
    int ia[] = {1, 1};
    int it = 1;
    
    ListNode* L = array2List(ia, ARRAYSIZE(ia)); PRINTLIST(L);
    
    ListNode* res = Solution().removeElements(L, it); PRINTLIST(res);
    return 0;
}

#endif
