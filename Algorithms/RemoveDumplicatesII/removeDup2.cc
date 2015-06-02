/*
copyright xu(xusiwei1236@163.com), all right reseved.

 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
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
public:
    static void removeNext(ListNode* prev) {
        ListNode *target = prev->next;
        prev->next = target->next;
        delete target;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode hint(0);
        hint.next = head;
        
        ListNode *ps = &hint; // prev of start.
        ListNode *curr = head->next, *prev = head;
        
        bool took = false;
        while(curr) {
            ListNode *next = curr->next;
            if(curr->val == ps->next->val) {
                took = true;
                removeNext(prev);
            }
            else {
                if(took) {
					removeNext(ps);
					took = false;
				}
                else ps = prev;
                prev = curr;
            }
            curr = next;
        }
        if(took) removeNext(ps);
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
    // int ia[] = { 1, 1, 1, 2, 3};
    // int ia[] = { 1, 1 };
    // int ia[] = { 1,1,2,2 };
    int ia[] = { 1,2,3,3,4,4,5 };
    int it = 1;
    
    ListNode* L = array2List(ia, ARRAYSIZE(ia)); PRINTLIST(L);
    
    ListNode* res = Solution().deleteDuplicates(L); PRINTLIST(res);
    return 0;
}

#endif
