/*
copyright xu(xusiwei1236@163.com), all right reserved.

House Robber
=============

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& A) { // non-negative integers
        const int N = A.size();
        if (N == 0) return 0;
        if (N == 1) return A[0];
        
        vector<int> dp(N, 0);
        dp[0] = A[0];
        dp[1] = max(A[0], A[1]);
        
        for (int i = 2; i < N; i++) {
            dp[i] = max(A[i] + dp[i-2], dp[i-1]);
        }
        return dp[N-1];
    }
};

int main(int argc, char* argv[])
{
    int n = 5;
    vector<int> v;
    
    srand(time(NULL));
    if (argc > 1) n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % n);
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
    
    cout << Solution().rob(v) << endl;
    return 0;
}
