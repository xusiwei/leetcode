/*
copyright xu(xusiwei1236@163.com), all right reserved.

Palindrome Linked List
======================

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = static_cast<int>(v.size()) - 1; i < j; i++, j--) {
            if (v[i] != v[j]) return false;
        }
        return true;
    }
};

void printList(ListNode* head);

namespace v2 {
class Solution {
    ListNode* getMidNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode help(0);
        while(head) {
            ListNode *next = head->next;
            head->next = help.next;
            help.next = head;
            head = next;
        }
        return help.next;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMidNode(head);
        ListNode* rev = reverseList(mid);
        // printList(head); printList(rev);
        for (ListNode *p = head, *q = rev; p != q && p && q; p = p->next, q = q->next) {
            if (p->val != q->val) {
                reverseList(rev); // resume another part orders
                return false;
            }
        }
        reverseList(rev); // resume another part orders
        return true;
    }
};
}

ListNode* createList(int a[], size_t n)
{
    ListNode* head = NULL;
    ListNode** tail = &head;
    for (int i = 0; i < n; i++) {
        ListNode* p = new ListNode(a[i]);
        *tail = p;
        tail = &p->next;
    }
    return head;
}

void printList(ListNode* head)
{
    while (head) {
        printf("%d%s", head->val, head->next ? "->" : "\n");
        head = head->next;
    }
}

void destroyList(ListNode* head)
{
    while (head) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main(int argc, char* argv[])
{
    int a[] = {1, 2, 2, 1};
    ListNode* head = NULL;

    if (argc <= 1) {
        head = createList(a, sizeof(a)/sizeof(a[0]));
    } else {
        vector<int> v;
        for (int i = 1; i < argc; i++) {
            v.push_back(atoi(argv[i]));
        }
        head = createList(v.data(), v.size());
    }

    printList(head);

    bool isPalindrome = false;
    srand(time(NULL));
    if (rand() % 2) {
        isPalindrome = v2::Solution().isPalindrome(head);
    } else {
        isPalindrome = Solution().isPalindrome(head);
    }

    printf("isPalindrome: %d\n", isPalindrome);

    printList(head);
    destroyList(head);

    return 0;
}
