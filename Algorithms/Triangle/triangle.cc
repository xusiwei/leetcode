/*
copyright xu(xusiwei1236@163.com), all right reserved.

Triangle
=========

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int sz = triangle.size();
        vector<int> cost(triangle[sz-1]); // last line cost.
        for(int i=sz-2; i>=0; i--) {
            for(int j=0; j<=i; j++) {
                cost[j] = triangle[i][j] + min(cost[j], cost[j+1]);
            }
        }
        return cost[0];
    }
};

