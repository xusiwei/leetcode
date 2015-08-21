/*
copyright xu(xusiwei1236@163.com), all right reserved.

Combination Sum
================

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
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
    int uniques_;
    int* times_;
    int* candidates_;
    vector<vector<int> >* result_;
public:
    void backtracking(int target, int index) {
        if(target < 0) return;
        if(target == 0) { // found an answer.
            vector<int> answer;
            for(int i = 0; i < uniques_; ++i) {
                answer.insert(answer.end(), times_[i], candidates_[i]);
            }
            result_->push_back(answer);
            return;
        }
        if(index >= uniques_) return;
        
        // select some candidates[index].
        for(int t = 0, tMax = target / candidates_[index]; t <= tMax; t++) {
            times_[index] = t;
            backtracking(target - t * candidates_[index], index+1);
        }
    }

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        
        sort(candidates.begin(), candidates.end());
        uniques_ = unique(candidates.begin(), candidates.end()) - candidates.begin();
        vector<int> times(uniques_, 0);
        
        result_ = &result;
        times_  = &times[0];
        candidates_ = &candidates[0];
        
        backtracking(target, 0);
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
