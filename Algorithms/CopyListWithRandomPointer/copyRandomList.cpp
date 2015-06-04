/*
copyright xu(xusiwei1236@163.com), all right reserved.

Copy List with Random Pointer
==================================

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
*/

#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdio>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL) return NULL;
        
        int count = 0;
        vector<RandomListNode*> id2ptr; // id -> new node.
        unordered_map<RandomListNode*, int> ptr2id; // old node -> id.

        // 0 <--> NULL
        ptr2id[NULL] = 0;
        id2ptr.push_back(NULL);
       
        RandomListNode fake(0), *tail = &fake;
        // dup list nodes.
        for(RandomListNode* p = head; p; p = p->next ) {
            RandomListNode* temp = new RandomListNode(p->label);
            ptr2id[p] = ++count;
            id2ptr.push_back(temp);
            tail->next = temp;
            tail = temp;
        }
        
        // dup random links.
        for(RandomListNode* p = head; p; p = p->next ) { // convert random link to ptr2id pair.
            int a = ptr2id[p];
            if(a) {
                int b = ptr2id[p->random];
                id2ptr[a]->random = id2ptr[b];
            }
        }
        
        return fake.next;
    }
};


#ifdef TEST
#define ARRAYSIZE(a) sizeof(a)/sizeof((a)[0])
// #define FUNC_TRACE puts(__func__);
#define FUNC_TRACE 

int printList(RandomListNode* head)
{FUNC_TRACE
    int count = 0;
    for(; head; head = head->next) {
        printf("-> %3d at %p", head->label, head);
        if(head->random) printf("  %3d*", head->random->label);
        puts("");
        count++;
    }
    return count;
}

#define PRINTLIST(list) do { puts(#list); int count = printList(list); printf("total: %d\n\n", count); } while(0)

RandomListNode* buildRandomList(int values[], int rlinks[], int length)
{FUNC_TRACE
    vector<RandomListNode*> id2ptr;
    
    // 0 <--> NULL
    id2ptr.push_back(NULL);
    
    RandomListNode fake(0), *tail = &fake;
    for(int i=0; i<length; ++i) {
        RandomListNode* temp = new RandomListNode(values[i]);
        id2ptr.push_back(temp);
        
        tail->next = temp;
        tail = temp;
    }
    
    RandomListNode* p = fake.next;
    for(int i=0; i<length; ++i) {
        p->random = id2ptr[rlinks[i]];
        p = p->next;
    }
    
    return fake.next;
}

int main()
{
    int values[] = { 10, 20, 30, 40, 50, 60 };
    int rlinks[] = {  3,  6,  1,  6,  2,  4 };
    
    RandomListNode* L = buildRandomList(values, rlinks, ARRAYSIZE(values)); PRINTLIST(L);

    PRINTLIST(Solution().copyRandomList(L));
    return 0;
}

#endif

