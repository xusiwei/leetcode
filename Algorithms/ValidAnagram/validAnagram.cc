/*
copyright xu(xusiwei1236@163.com), all right reserved.

Valid Anagram
==============

Given two strings s and t, write a function to determine if t is an anagram of s. 

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.


Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        const int N = 256;
        char map1[N] = {0}, map2[N] = {0};

        for (int i = 0; i < s.length(); i++) {
            map1[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            map2[t[i]]++;
        }
        return memcmp(map1, map2, sizeof(map1)) == 0;
    }

};

int main(int argc, char* argv[])
{
    string s = "anagram";
    string t = "nagaram";

    if (argc > 2) {
        s = argv[1];
        t = argv[2];
    }
    cout << s << endl;
    cout << t << endl;
    cout << Solution().isAnagram(s, t) << endl;
    return 0;
}
