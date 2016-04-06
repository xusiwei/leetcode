/*
copyright xu(xusiwei1236@163.com), all right reserved.

Best Time to Buy and Sell Stock IV
===================================

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:Special thanks to @Freezen for adding this problem and creating all test cases.
*/
#include <limits.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& P) {
        const int n = P.size();
        if (k >= n/2) {
            int sum = 0;
            for (int i = 1; i < n; i++) {
                sum += max(P[i] - P[i-1], 0);
            }
            return sum;
        }
        
        // k < n/2;
        // dp[i][j] := maxProfit(i, P[0...j])
        //
        // dp[i][j] = max(dp[i][j-1], // do not transacte today
        //                max{ dp[i-1][t] + P[j] - P[t+1] | 0 <= t < j }
        //            );
        vector<vector<int>> dp(k+1, vector<int>(n+1));
        for (int i = 1; i <= k; i++) {
            int imax = INT_MIN;
            for (int j = 0; j < n; j++) {
                dp[i][j+1] = max(dp[i-1][j+1], max(dp[i][j], P[j] + imax));
                imax = max(imax, dp[i-1][j] - P[j]);
            }
        }
        return dp[k][n];
    }
};

int main(int argc, char* argv[])
{
    int k = 5;
    int n = 10;
    if (argc > 1) k = atoi(argv[1]);
    if (argc > 2) n = atoi(argv[2]);
    
    vector<int> P;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        P.push_back(rand() % n);
        cout << P.back() << ",";
    }
    cout << endl;
    
    cout << "maxProfit: " << Solution().maxProfit(k, P) << endl;
    return 0;
}
