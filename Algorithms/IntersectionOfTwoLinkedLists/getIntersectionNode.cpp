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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hash;
        for(ListNode* p = headA; p; p = p->next) {
            hash.insert(p);
        }
        for(ListNode* p = headB; p; p = p->next) {
            if(hash.find(p) != hash.end()) {
                return p;
            }
        }
        return NULL;
    }
};