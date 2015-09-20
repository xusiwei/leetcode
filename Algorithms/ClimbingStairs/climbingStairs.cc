/*
copyright xu(xusiwei1236@163.com), all right reserved.

Climbing Stairs
================

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
//  x   x   x   x   x   x   ^
//  13  8   5   3   2   1
class Solution {
public:
    int climbStairs(int n) {
#ifdef BUFFER
        if(n <= 2) return n;
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        dp[n-2] = 2;
        for(int i = n-3; i >= 0; i--) {
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
#else
        if(n <= 2) return n;
        int dp0 = 0, dp1 = 1, dp2 = 2;
        for(int i = n-3; i >= 0; i--) {
            dp0 = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp0;
        }
        return dp0;
#endif
    }
};
