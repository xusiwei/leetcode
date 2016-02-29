/*
copyright xu(xusiwei1236@163.com), all right reserved.

Interleaving String
====================

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.



For example,
Given:
s1 = "aabcc",
s2 = "dbbca",


When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        
        // invariant: len3 == len1 + len2
        if (len1 + len2 != len3) return false;
        if (s1 + s2 == s3) return true;

        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1));
        // dp[i][j] := isInterleave(s1.substr(0, i), s2.substr(0, j), s3.substr(0, i+j))
        // 
        //    i, j = 0, 0    =>   isInterleave("", "", "") : true
        //
        //          dp[0][0] = true
        //
        //    i = 0, j > 0   =>   isInterleave("", "xxx", "yyy")
        //
        //          dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1]
        //
        //    i > 0, j = 0   =>   isInterleave("xxx", "", "yyy")
        //
        //          dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1]
        //
        //    i > 0, j > 0   =>   isInterleave("xxx", "yyy", "zzz")
        //
        //          dp[i][j] =   dp[i-1][j] && s1[i-1] == s3[i+j-1]
        //                    || dp[i][j-1] && s2[j-1] == s3[i+j-1]
                
        dp[0][0] = true;
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                dp[i][j] = s3[i+j-1] == s1[i-1] && dp[i-1][j] || s3[i+j-1] == s2[j-1] && dp[i][j-1];
            }
        }
        return dp[len1][len2];
    }
};

int main(int argc, char* argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";
    
    if (argc > 1) s1 = argv[1];
    if (argc > 2) s2 = argv[2];
    if (argc > 3) s2 = argv[3];

    cout << Solution().isInterleave(s1, s2, s3) << endl;
    return 0;
}
