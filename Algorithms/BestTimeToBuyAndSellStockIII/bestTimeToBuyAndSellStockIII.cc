/*
copyright xu(xusiwei1236@163.com), all right reserved.

Best Time to Buy and Sell Stock III
====================================

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

//
//
// split prices to two range: p[0, i) and p[i, n), assume m is the max profit when we have two transactions, then
//
//   m = max{ p1(p[0,i)) + p1(p[i,n)) | i = 1, 2, ..., n-1}
//
//
// assume mp is max profit when you only one transaction, then
//
//   mp = p1(p[0...n-1]) = max{max(mp, p[i] - buy), buy = min(buy, p[i]) | mp = 0, buy = p[0], i = 1, 2, ..., n-1}
//
//
// define prev[i] = p1(p[0...i-1]), last[i] = p1(p[i...n-1]), then
//
//   prev[i] = { max(prev[i-1], p[i] - buy), buy = min(buy, p[i]) | prev[0] = 0, buy = p[0], i = 1, 2, ..., n-1}
//
//   last[i] = { max(last[i+1, sell - p[i]), sell = max(sell, p[i]) | last[n-1] = 0, sell = p[n-1], i = n-2, ..., 0}
//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (0 == n || 1 == n) return 0;

        int buy = prices[0];
        vector<int> prev(n, 0);
        for (int i = 1; i < n; i++) {
            prev[i]    = max(prev[i-1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }

        int sell = prices[n-1];
        vector<int> last(n, 0);
        for (int i = n-2; i >= 0; i--) {
            last[i] = max(last[i+1], sell - prices[i]);
            sell = max(sell, prices[i]);
        }

        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, prev[i] + last[i]); 
        }
        return m; 
    }
};

int main(int argc, char* argv[])
{
    vector<int> prices{2,1,2,0,1};  // {1,4,2}; // 
    if (argc > 1) prices.clear();
    for (int i = 1; i < argc; i++) {
        int p = atoi(argv[i]);
        printf("prices[%d]: %d\n", i, p);
        prices.push_back(p);
    }
    printf("maxProfit: %d\n", Solution().maxProfit(prices));
    return 0;
}
