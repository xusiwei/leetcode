/*
copyright xu(xusiwei1236@163.com), all right reserved.

Min Stack
==========

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.


push(x) -- Push element x onto stack.


pop() -- Removes the element on top of the stack.


top() -- Get the top element.


getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
public:
    vector<pair<int, int>> stack_;

    void push(int x) {
        stack_.push_back(make_pair(x, stack_.empty() ? x : min(x, stack_.back().second)));
    }

    void pop() {
        if (stack_.size() > 0) {
            stack_.pop_back();
        }
        // else throw "unexpected pop";
    }

    int top() {
        // if (stack_.size() > 0) {
        //     return stack_.back().first;
        // }
        // throw "unexpected top";
        return stack_.size() > 0 ? stack_.back().first : INT_MAX;
    }

    int getMin() {
        // if (stack_.size()) {
        //     return stack_.back().second;
        // }
        // throw "unexpected getMin";
        return stack_.size() > 0 ? stack_.back().second : INT_MAX;
    }
};
