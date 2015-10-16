/*
copyright xu(xusiwei1236@163.com), all right reserved.

Combination Sum II
===================

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename Vector>
void printVector(Vector v);

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target) {
        vector<vector<int> > res;        
        sort(num.begin(), num.end());
        
        vector<int> cur;
        backtrack(num, res, cur, target, 0);
        return res;
    }
    
    void backtrack(vector<int>& num, vector<vector<int> >& res, vector<int>& cur, int target, int idx) {
        if(target == 0) res.push_back(cur);
        if(target < 0) return;
        for(int sz = num.size(); idx < sz && num[idx] <= target; ++idx) {
            cur.push_back(num[idx]);
            //cout << idx << ": "; printVector(cur);
            backtrack(num, res, cur, target - num[idx], idx + 1);
            cur.pop_back();
            while(idx+1 < sz && num[idx+1] == num[idx]) ++idx;
        }
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

template<typename Vector>
void printVector(Vector v)
{
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "\n" : " ");
    }
}

int main(int argc, char* argv[])
{
    int target, n;
    vector<int> nums;
    
    cin >> target;
    while(cin >> n) {
        nums.push_back(n);
    }
    
    printMatrix(Solution().combinationSum2(nums, target));
    return 0;
}
