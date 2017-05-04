/*
copyright xu(xusiwei1236@163.com), all right reserved.

Permutation in String
======================

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:

Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").



Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False



Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int N = 128u, L1 = s1.size(), L2 = s2.size();
        if (L1 > L2) return false;
        
        vector<int> tab(N, 0);
        for (char c: s1) tab[c]++;
        
        vector<int> win(N, 0);
        for (int i = 0; i < L1; i++) {
            win[s2[i]]++;
        }
        
        if (memcmp(win.data(), tab.data(), sizeof(win[0]) * win.size()) == 0) return true;
        for (int i = L1; i < L2; i++) {
            win[s2[i - L1]]--;
            win[s2[i]]++;
            if (memcmp(win.data(), tab.data(), sizeof(win[0]) * win.size()) == 0) return true;
        }
        return false;
    }
};


int main(int argc, char* argv[])
{
    string s1 = "ab", s2 = "eidbaooo";
    if (argc > 1) s1 = argv[1];
    if (argc > 2) s2 = argv[2];

    cout << s1 << endl;
    cout << s2 << endl;
    cout << Solution().checkInclusion(s1, s2) << endl;
    return 0;
}
