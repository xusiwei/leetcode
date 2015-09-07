/*
copyright xu(xusiwei1236@163.com), all right reserved.

Unique Paths II
================

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        
        int col = grid[0].size();
        // dp[r][c] means unique paths from (r, c) to the right bottom.
        vector<int> dp(col); //vector<vector<int>> dp(row, vector<int>(col));
        
        for(int r = row-1; r >= 0; r--) {
            for(int c = col-1; c >= 0; c--) {
                if(grid[r][c]) {
                    dp[c] = 0;
                }
                else if(r == row-1 && c == col-1) {
                    dp[c] = 1;
                }
                else if(r == row-1) {
                    dp[c] = dp[c+1];
                }
                else if(c == col-1) {
                    dp[c] = dp[c];
                }
                else {
                    dp[c] = dp[c] + dp[c+1];
                }
            }
        }
        
        return dp[0];
    }
};
