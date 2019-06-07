/*
copyright xu(xusiwei1236@163.com), all right reserved.

Search A 2D Matrix II
=====================

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/

#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
        // row first search
        for (auto& row: M) {
            if (binary_search(row.begin(), row.end(), target)) {
                return true;
            }
        }
        return false;
    }
};

namespace v2 {

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
        if (M.empty()) return false;
        // if (M.size() == 1) return binary_search(M[0].begin(), M[0].end(), target);

        int i = 0, j = M[0].size() - 1;
        while (i < M.size() && j >= 0) {
            int x = M[i][j];
            if (x == target) return true;
            else if (x > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};

} // namespace v2


int main(int argc, char* argv[])
{
    vector<vector<int>> matrix {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},

        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = argc > 1 ? atoi(argv[1]) : 10;
    cout << "matrix: " << endl;
    for_each(matrix.begin(), matrix.end(), [](vector<int>& row) {
        for_each(row.begin(), row.end(), [](int n){
            cout << n << "\t";
        });
        cout << endl;
    });

    v2::Solution s;
    cout << "search " << target << ":\t" << s.searchMatrix(matrix, target) << endl;
    for_each(matrix.begin(), matrix.end(), [&](vector<int>& row) {
        for_each(row.begin(), row.end(), [&](int n) {
            cout << "search " << n << " => \t" << s.searchMatrix(matrix, n) << endl;
        });
    });
    return 0;
}
