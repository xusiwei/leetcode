/*
copyright xu(xusiwei1236@163.com), all right reserved.

Word Break
===========

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.


For example, given
s = "leetcode",
dict = ["leet", "code"].



Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        vector<int> stack;
        unordered_set<int> visited;
        
        stack.push_back(0);
        while (stack.size() > 0) {
            int start = stack.back(); // word start
            stack.pop_back();
            if (visited.count(start) == 0) {
                visited.insert(start);
                for (int e = start+1; e <= s.length(); e++) {
                    string word = s.substr(start, e-start);
                    if (dict.count(word) > 0) {
                        if (e == s.length()) return true;
                        stack.push_back(e);
                    }
                }
            }
        }
        return false;
    }
};
