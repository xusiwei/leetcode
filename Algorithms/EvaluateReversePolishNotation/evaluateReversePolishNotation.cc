/*
copyright xu(xusiwei1236@163.com), all right reserved.

Evaluate Reverse Polish Notation
=================================

Evaluate the value of an arithmetic expression in Reverse Polish Notation.



Valid operators are +, -, *, /. Each operand may be an integer or another expression.



Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result = 0;
        vector<int> stack;
        int size = tokens.size();
        if (size == 1) return atoi(tokens[0].c_str());
        
        for (int i = 0; i < size; i++) {
            string &s = tokens[i];
            if (s.length() == 1 && !isdigit(s[0]) ) { // operator
                int b = stack.back(); stack.pop_back(); // rhs
                int a = stack.back(); stack.pop_back(); // lhs
                if (0) ;
                else if (s == "+") result = a+b;
                else if (s == "-") result = a - b;
                else if (s == "*") result = a * b;
                else if (s == "/") result = a / b;
                stack.push_back(result);
            } else {
                stack.push_back(atoi(s.c_str()));
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
#define TEST(...) do { \
        const char* a[] = {__VA_ARGS__}; \
        vector<string> v;                  \
        for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) { \
            cout << a[i] << ", "; \
            v.push_back(a[i]); \
        } \
        cout << "-> " << Solution().evalRPN(v) << endl; \
    } while(0)

    TEST("2", "1", "+", "3", "*");
    TEST("4", "13", "5", "/", "+");
    
    vector<string> v;
    for (int i = 1; i < argc; i++) {
        v.push_back(argv[i]);
    }
    cout << "-> " << Solution().evalRPN(v) << endl;
    return 0;
}

