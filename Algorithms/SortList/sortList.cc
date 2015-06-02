/*
copyright xu(xusiwei1236@163.com), all right reserved.

Sort a linked list in O(n log n) time using constant space complexity.
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
	ListNode *sortList(ListNode *head) {
		if(head == NULL || head->next == NULL) return head;
		
		// divide to two part(as same length).
		ListNode *fast = head->next, *slow = head;
		while(fast) {
			fast = fast->next;
			if(fast == NULL) break;
			slow = slow->next;
			fast = fast->next;
		}
		ListNode *half = slow->next;
		slow->next = NULL;
		
		// sort them respectively.
		head = sortList(head);
		half = sortList(half);

		// merge the two sorted part.
		ListNode fake(0), *tail = &fake;
		while( head && half ) {
			// make sure head lesser.
			if(head->val >= half->val) std::swap(head, half);
			// add it to the end of sorted list.
			tail->next = head;
			tail = head;
			head = head->next;
		}
		tail->next = head ? head : half;
		return fake.next;        
	}
};