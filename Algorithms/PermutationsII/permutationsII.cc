/*
copyright xu(xusiwei1236@163.com), all right reserved.

Permutations II
================

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename Vector>
void printVector(Vector v);

#ifdef RECUSIVE
// TLE O(A(n, n))
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& cur, int t) {
        if(t >= cur.size()) {
            res.push_back(cur);
        }
        
        // in the permutation tree, t indicates level, i indicates branch.
        for(int i = t, sz = cur.size(); i < sz; i++) {
            if(i > t && cur[i] == cur[t]) { 
                // if current branch has the same value as previous growth,
                // cut down it, and continue others.
                continue;
            }
            swap(cur[i], cur[t]);
            backtrack(res, cur, t+1);
            swap(cur[i], cur[t]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        backtrack(res, num, 0);
        return res;
    }
};
#else // RECUSIVE
// O(n^3)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
        vector<vector<int>> res;
        res.push_back(num);
        
        for(int pos = 0;  pos < num.size(); pos++) {
            int size = res.size();
            for(int i = 0; i < size; i++) {
                sort(res[i].begin() + pos, res[i].end());
                for(int j = pos+1; j < res[i].size(); j++) {
                    vector<int> v = res[i];
                    if(v[j-1] == v[j]) continue;
                    swap(v[j], v[pos]);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};
#endif // RECUSIVE

template<typename Vector>
void printVector(Vector v)
{
    cout << "[";
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "]" : ",");
    }
}

template<typename Matrix>
void printMatrix(Matrix m)
{
    cout << "[";
    for(int i = 0, isz = m.size(); i < isz; i++) {
        printVector(m[i]);
        cout << (i+1 == isz ? "]\n" : ",");
    }
}

int main(int argc, char* argv[])
{
    int n;
    vector<int> vec;
    
    while(cin >> n) {
        vec.push_back(n);
    }
    //printVector(vec); cout << endl;
    printMatrix(Solution().permuteUnique(vec));
    return 0;
}
