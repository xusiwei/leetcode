/*
copyright xu(xusiwei1236@163.com), all right reserved.

Best Time to Buy and Sell Stock
================================

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (0 == len || 1 == len) return 0;

        int result = 0, buy = prices[0];
        for (int i = 1; i < len; i++) {
            // try to sell out
            int delta = prices[i] - buy;
            if(delta > result) result = delta;

            // try to buy in
            if(prices[i] < buy) buy = prices[i]; 
        }
        return result;
    }
};

