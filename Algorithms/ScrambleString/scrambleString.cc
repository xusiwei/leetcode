/*
copyright xu(xusiwei1236@163.com), all right reserved.

Scramble String
================

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;
        
        string d1 = s1;
        string d2 = s2;
        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());
        if (d1 != d2) return false;
        
        int len = s1.length();
        for (int i = 1; i < len; i++) {
            if (   ( isScramble(s1.substr(0,       i), s2.substr(0, i      )) 
                  && isScramble(s1.substr(i, len - i), s2.substr(i, len - i)) )
                || ( isScramble(s1.substr(0,       i), s2.substr(len - i, i))
                  && isScramble(s1.substr(i, len - i), s2.substr(0, len - i)) )  ) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    string s1 = "great";
    string s2 = "rgtae";
    if (argc > 2) {
        s1 = argv[1];
        s2 = argv[2];
    }
    
    cout << Solution().isScramble(s1, s2) << endl;
    return 0;
}
