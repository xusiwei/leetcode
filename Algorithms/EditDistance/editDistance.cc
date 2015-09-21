/*
copyright xu(xusiwei1236@163.com), all right reserved.

Edit Distance
==============

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
    /**
     * dp[i][j] is minDistance(word1[0...i), word2[0...j))
     * 
     * if word1[i-1] == word2[j-1], 
     *      dp[i][j] = dp[i-1][j-1]
     * else
     *      dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1)
     *                      insert          delete          replace
     * 
     * word1 : "abb", word2 : "abccd"
     * 
     * 1 ) initailize matrix:
     *    "" a b c c d 
     * ""  0 1 2 3 4 5
     *  a  1
     *  b  2
     *  b  3
     * 
     * 2 ) dynmaic programming:
     *    "" a b c c d 
     * ""  0 1 2 3 4 5
     *  a  1 0 1 2 3 4
     *  b  2 1 0 1 2 3
     *  b  3 2 1 1 2 3
     * 
     **/
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1 == 0) return n2;
        if(n2 == 0) return n1;
        
        vector<vector<int> > dp(n1+1, vector<int>(n2+1));
        for(int i = 0; i <= n1; i++) dp[i][0] = i;
        for(int j = 0; j <= n2; j++) dp[0][j] = j;
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};

