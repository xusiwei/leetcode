/*
copyright xu(xusiwei1236@163.com), all right reserved.

Longest Substring Without Repeating Characters
===============================================

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1); // last position.
        int start = 0, result = 0;
        
        for(int i = 0; i < s.length(); ++i) {
            start = max(last[s[i]] + 1, start);
            last[s[i]] = i;
            result = max(result, i - start + 1); // LWRS end with s[i].
        }
        return result;
    }
};
