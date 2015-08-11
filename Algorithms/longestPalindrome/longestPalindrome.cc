/*
copyright xu(xusiwei1236@163.com), all right reserved.

Longest Palindromic Substring
===============================

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 1, start = 0, length = s.length();
        
        for(int i = 0; i < length; ++i) {
        	printf("i: %d\n", i);
            // for odd
            for(int l=i-1, r=i+1; l >= 0 && r < length; l--, r++) {
                if(s[l] == s[r]) {
                    if(r - l + 1 > maxlen) {
                        maxlen = r - l + 1;
                        start = l;
                    }
                }
                else break;
            }
            
            // for even
            for(int l=i, r=i+1; l >= 0 && r < length; l--, r++) {
                if(s[l] == s[r]) {
                    if(r - l + 1 > maxlen) {
                        maxlen = r - l + 1;
                        start = l;
                    }
                }
                else break;
            }
            
        }
//        cout << maxlen << endl;
        return s.substr(start, maxlen);
    }
};

int main()
{
	string s = "caba";
	cin >> s;
	cout << Solution().longestPalindrome(s) << endl;
	return 0;
}

