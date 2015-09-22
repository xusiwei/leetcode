/*
copyright xu(xusiwei1236@163.com), all right reserved.

Combinations
=============

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& cur, int n, int k) {
        if(k == 0) {
            vector<int> v = cur;
            sort(v.begin(), v.end());
            res.push_back(v);
        }
        
        for(int i = 1; i <= n; i++) {
            cur.push_back(i);
            backtrack(res, cur, i-1, k-1);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        backtrack(res, cur, n, k);
        return res;
    }
};

int main(int argc, char* argv[])
{
    int n = 6, k = 3;
    if(argc > 1) n = atoi(argv[1]);
    if(argc > 2) k = atoi(argv[2]);
    
    auto matrix = Solution().combine(n, k);
    for(auto& v : matrix) {
        for(int i: v) {
            cout << i << ", ";
        }
        cout << "\n";
    }
    return 0;
}
