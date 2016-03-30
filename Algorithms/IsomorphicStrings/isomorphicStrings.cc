/*
copyright xu(xusiwei1236@163.com), all right reserved.

Isomorphic Strings
===================

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        char ms[256] = {0}, mt[256] = {0}; // replace is bidirectional.
        for (int i = 0; i < s.length(); i++) {
            if (ms[s[i]] != mt[t[i]]) return false;
            ms[s[i]] = i+1;
            mt[t[i]] = i+1;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    string s = "paper";
    string t = "title";
    if (argc > 1) s = argv[1];
    if (argc > 2) t = argv[2];

    cout << Solution().isIsomorphic(s, t) << endl;
    return 0;
}
