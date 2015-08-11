/*
copyright xu(xusiwei1236@163.com), all right reserved.

Longest Substring Without Repeating Characters
===============================================

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
    static bool isPalindrome(string& s, int beg, int end) {
        for(int i = beg, j = end-1; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    
public:
    string longestPalindrome(string s) {
        int max = 0, len = s.length();
        int beg = 0, end = 0;
        
        for(int i = 0; i < len; ++i) {
            for(int j = i+1; j <= len; ++j) {
            	int L = j - i;
             	bool isp = isPalindrome(s, i, j);
             	// printf("%d, %d: %s -> %s\n", i, j, s.substr(i, j-i).c_str(), isp ? "true" : "false");
                if(isp && L > max) {
                    max = L;
                    beg = i;
                    end = j;
                }
            }
        }
        
        return s.substr(beg, end - beg);
    }
};

int main()
{
	string s;
	cin >> s;
	cout << Solution().longestPalindrome(s) << endl;
	return 0;
}

