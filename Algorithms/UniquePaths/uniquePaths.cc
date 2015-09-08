/*
copyright xu(xusiwei1236@163.com), all right reserved.

Unique Paths
=============

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int row, int col) {
        //vector<vector<int>> dp(row, vector<int>(col));
        vector<int> dp(col); // space optimized.
        
        for(int r = row-1; r >= 0; r--) {
            for(int c = col-1; c >= 0; c--) {
                if(r == row-1 || c == col-1) {
                    dp[c] = 1;
                }
                else {
                    dp[c] = dp[c] + dp[c+1];
                }
            }
        }
        
        return dp[0];
    }
};
