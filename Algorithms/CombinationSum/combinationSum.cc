/*
copyright xu(xusiwei1236@163.com), all right reserved.

Combination Sum
================

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]

*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& num, vector<int>& times, vector<vector<int> >& result, int target, int index) {
        if(target < 0) return;
        if(target == 0) { // found an answer.
            vector<int> answer;
            for(int i = 0, sz = times.size(); i < sz; ++i) {
                answer.insert(answer.end(), times[i], num[i]);
            }
            result.push_back(answer);
            return;
        }
        if(index >= times.size()) return;
        
        // select some num[index].
        for(int t = 0, tMax = target / num[index]; t <= tMax; t++) {
            times[index] = t;
            backtracking(num, times, result, target - t * num[index], index + 1);
        }
    }
    
    vector<vector<int> > combinationSum(vector<int>& num, int target) {
        vector<vector<int> > result;
        
        sort(num.begin(), num.end());
        int count = unique(num.begin(), num.end()) - num.begin();
        vector<int> times(count, 0);
        
        backtracking(num, times, result, target, 0);
        return result;
    }
};


template<typename Matrix>
void printMatrix(Matrix m)
{
    for(int i = 0; i < m.size(); i++) {
        cout << "[";
        for(int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << (j+1 == m[i].size() ? "]\n" : ",");
        }
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int target, n;
    vector<int> nums;
    
    cin >> target;
    while(cin >> n) {
        nums.push_back(n);
    }
    
    printMatrix(Solution().combinationSum(nums, target));
    return 0;
}
