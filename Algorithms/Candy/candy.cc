/*
copyright xu(xusiwei1236@163.com), all right reserved.

Candy
======

There are N children standing in a line. Each child is assigned a rating value. 


You are giving candies to these children subjected to the following requirements:


Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.


What is the minimum candies you must give?
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        if (N <= 1) return N;
        vector<int> num(N, 1);
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i-1]) {
                num[i] = num[i-1] + 1;
            }
        }
        for (int i = N-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                num[i] = max(num[i], num[i+1] + 1);
            }
        }
        int total = 0;
        for (int i = 0; i < N; i++) total += num[i];
        return total;
    }
};
