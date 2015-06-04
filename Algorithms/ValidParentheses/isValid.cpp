/*
copyright xu(xusiwei1236@163.com), all right reserved.

Valid Parentheses
=====================

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Show Tags
Have you met this question in a real interview? Yes  No
Discuss


*/

class Solution {
public:
    bool match(char a, char b) { // Parentheses match.
        return a == '(' && b == ')'
            || a == '[' && b == ']'
            || a == '{' && b == '}';
    }
    
    bool isValid(string s) {
        if(s.length() == 0) return true;
        if(s.length() == 1) return false;

        stack<char> cs; // checking statck.
        for(int i=0; i<s.length(); ++i) {
            if(cs.empty()) cs.push(s[i]);
            else if(match(cs.top(), s[i])) cs.pop();
            else cs.push(s[i]);
        }
        return cs.empty();
    }
};
