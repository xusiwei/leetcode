/*
copyright xu(xusiwei1236@163.com), all right reserved.

Subsets II
===========

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& S) {
        vector<vector<int> > result;
        vector<int> t;
        int n = S.size();
        sort(S.begin(), S.end());
        for (int k = 0; k <= n; ++k) {
            vector<vector<int> > c;
            combine(c, S, n, k, t);
            result.insert(result.end(), c.begin(), c.end());
        }
        return result;
    }
    
    void combine(vector<vector<int> >& out, vector<int>& v, int n, int k, vector<int>& t) {
        if (k == 0) {
            vector<int> cp(t);
            sort(cp.begin(), cp.end());
            out.push_back(cp);
        } else {
            for (int i = n-1; i >= 0; i--) {
                t.push_back(v[i]);
                combine(out, v, i, k-1, t);
                t.pop_back();
                // skip duplicates
                while (v[i-1] == v[i]) i--;
            }
        }
    }
};

template <class Matrix>
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << ",";
        }
        cout << "\n";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<int> vec;
    for (int i = 1; i < argc; ++i) {
        vec.push_back(atoi(argv[i]));
    }
    printMatrix(Solution().subsetsWithDup(vec));
    return 0;
}
