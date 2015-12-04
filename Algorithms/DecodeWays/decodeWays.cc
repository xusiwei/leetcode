/*
copyright xu(xusiwei1236@163.com), all right reserved.

Decode Ways
============

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
#include <ctype.h>
#include <assert.h>
#include <vector>
#include <string>
//#include <stdexcept>
#include <iostream>
using namespace std;

class Solution {
public:
    static bool nzero(char c) {
        return c != '0';
    }

    static bool jionable(char c1, char c2) {
        return c1 == '1' || (c1 == '2' && c2 <= '6');
    }

    int numDecodings(string s) {
        // 0 => 0, 1 => 1, 2 => 1, 3 => 1
        // 12 => 2, 23 => 2, 33 => 1, 44 => 1
        // Dynmaic Programming:
        // dp[n] is numDecodings(s[0...n])
        // if s[n-1], s[n] jionable, there are two ways:
        //    decode(s[0...n-2]) + mapping(jion(s[n-1], s[n]))
        //    if s[n] != '0':
        //       decode(s[n...n-1]) + mapping(s[n])
        // else if s[n] != '0':
        //    decode(s[0...n-1]) + mapping(s[n])
        // else:
        //    unexpected case.
        // => dp[n] = dp[n-2] if joinable(s[n-1], s[n])
        //                   + dp[n-1] if s[n] != '0'
        //          = dp[n-1] else if s[n] != '0'
        if (s.length() == 0) return 0;
        
        vector<int> dp(s.length());
        dp[0] = (nzero(s[0]) ? 1 : 0);
        if (s.length() == 1) return dp[0];
        
        dp[1] = jionable(s[0], s[1]) ? 1 : 0;
        dp[1] += nzero(s[0]) && nzero(s[1]) ? 1 : 0;
        for (int i = 2; i < s.length(); i++) {
            assert(isdigit(s[i]));
            if (jionable(s[i-1], s[i])) {
                dp[i] = dp[i-2];
                if (nzero(s[i])) {
                    dp[i] += dp[i-1];
                }
            } else if(nzero(s[i])) {
                dp[i] = dp[i-1];
            } else {
                return 0; // throw logic_error("unexpected input");
            }
        }
        return dp[s.length() - 1];
    }
};

int main(int argc, char* argv[])
{
    string str = "123123";
    if (argc > 1) str = argv[1];
    for (int i = 0; i < str.length(); i++) {
        string s = str.substr(0, i+1);
        cout << s << " => " << Solution().numDecodings(s) << endl;
    }
    return 0;
}

