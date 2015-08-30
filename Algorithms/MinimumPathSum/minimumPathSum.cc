/*
copyright xu(xusiwei1236@163.com), all right reserved.

Minimum Path Sum
=================

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        int col = grid[0].size();

        // startFrom(r, c) = grid[r][c] when r == row-1 && c == col-1
        //                 = grid[r][c] + startFrom(r, c+1) when r == row-1
        //                 = grid[r][c] + startFrom(r+1, c) when c == col-1
        //                 = grid[r][c] + min(startFrom(r+1, c), startFrom(r, c+1)) others.
        // dp[r][c] means min path sum from (r, c) to right bottom.
        // vector<vector<int> > dp;
        vector<int> dp(col); // space optimized dynamic programming.
        for(int r = row-1; r >= 0; r--) {
            for(int c = col-1; c >= 0; c--) {
                if(r == row-1 && c == col-1) dp[c] = grid[r][c];
                else if(r == row-1) dp[c] = grid[r][c] + dp[c+1];
                else if(c == col-1) dp[c] = grid[r][c] + dp[c];
                else dp[c] = grid[r][c] + min(dp[c], dp[c+1]);
            }
        }
        
        return dp[0];
    }
};

