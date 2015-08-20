/*
copyright xu(xusiwei1236@163.com), all right reserved.

Longest Valid Parentheses
==========================

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stk;
        int result = 0;
        int mark = -1;
        for(int i = 0, sz = s.length(); i < sz; ++i) {
            const char c = s[i];
            if(c == '(') {
                stk.push_back(i);
            }
            else if(c == ')') {
                if(stk.size() == 0) { // error-formed.
                    mark = i;
                }
                else {
                    stk.pop_back();
                    
                    int formed = 0;
                    
                    if(stk.size() == 0)  formed = i - mark;
                    else formed = i - stk.back();
                    
                    if(formed > result) result = formed;
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    string s = ")()()";
    cout << Solution().longestValidParentheses(s) << endl;
    return 0;
}
