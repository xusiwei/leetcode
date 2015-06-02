/*
copyright xu(xusiwei1236@163.com), all right reserved.

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1, *q = l2; // iterator
        ListNode fake(0), *tail = &fake; // result list head and tail.
        
        while(p && q) {
            if(p->val >= q->val) std::swap(p, q);
            tail->next = p;
            tail = p;
            p = p->next;
        }
        
        tail->next = p ? p : q;
        return fake.next;
    }
    
    ListNode* mergeProxy(vector<ListNode*>& lists, int beg, int end) {
        if(beg == end) return NULL;
        if(beg+1 == end) return lists[beg];
        int mid = beg + (end-beg)/2;
        return mergeTwoLists(mergeProxy(lists, beg, mid), mergeProxy(lists, mid, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeProxy(lists, 0, (int)lists.size());
    }
};