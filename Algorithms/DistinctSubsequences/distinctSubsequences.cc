/*
copyright xu(xusiwei1236@163.com), all right reserved.

Distinct Subsequences
======================

Given a string S and a string T, count the number of distinct subsequences of T in S.



A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).



Here is an example:
S = "rabbbit", T = "rabbit"


Return 3.
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        const int slen = S.length(), tlen = T.length();
        if (slen < tlen) return false;
        
        vector<vector<int> > dp(tlen+1, vector<int>(slen+1));
        // S  -- deleting some of the characters --> T
        // 
        // dp[i][j] := numDistinct(S.substr(0,j), T.substr(0,i))
        // 
        // 1) i = 0       =>    dp[i][j]  =  1    (deleting all of characters in S)
        // 
        // 2) i > j       =>    dp[i][j]  =  0    (can not construct T by deleting some characters in S)
        // 
        // 3) if T[i-1] != S[j-1], deleting S[j-1] from S.
        //                
        //                =>    dp[i][j]  =  dp[i][j-1]
        //                
        //    else // T[i-1] == S[j-1]
        //                
        //                =>    dp[i][j]  =  dp[i][j-1]   (discard equal, deleting S[j-1])
        //                                 + dp[i-1][j-1] (skip equals, don't deleting S[j-1])

        for (int j = 0; j <= slen; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= tlen; i++) {
            for (int j = 0; j <= slen; j++) {
                if (i > j) {
                    dp[i][j] = 0;
                } else if (S[j-1] != T[i-1]) {
                    dp[i][j] = dp[i][j-1];
                } else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
            }
        }
        
        return dp[tlen][slen];
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
