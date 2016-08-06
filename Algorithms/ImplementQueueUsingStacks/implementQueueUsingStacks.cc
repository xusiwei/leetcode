/*
copyright xu(xusiwei1236@163.com), all right reserved.

Implement Queue using Stacks
=============================

Implement the following operations of a queue using stacks.


push(x) -- Push element x to the back of queue.


pop() -- Removes the element from in front of queue.


peek() -- Get the front element.


empty() -- Return whether the queue is empty.


Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/
#include <stdlib.h>

#include <stack>
#include <iostream>
using namespace std;


class Queue {
    stack<int> stk;
public:

    // Push element x to the back of queue.
    void push(int x) {
        stk.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        while(stk.size() > 1) {
            int t = stk.top(); stk.pop();
            tmp.push(t);
        }

        stk.pop();
        while(!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int res = 0;
        stack<int> tmp;

        while(stk.size() > 1) {
            int t = stk.top(); stk.pop();
            tmp.push(t);
        }

        res = stk.top();
        while(!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }

        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};

int main(int argc, char* argv[])
{
	int a[] = {1, 2, 3, 4, 5};

	Queue q;
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		q.push(a[i]);
	}

	for (int i = 1; i < argc; i++) {
		q.push(atoi(argv[i]));
	}

	while (!q.empty()) {
		cout << q.peek() << endl;
		q.pop();
	}
    return 0;
}
