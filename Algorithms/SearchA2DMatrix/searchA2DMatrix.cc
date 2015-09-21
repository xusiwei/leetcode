/*
copyright xu(xusiwei1236@163.com), all right reserved.

Search a 2D Matrix
===================

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        auto it = lower_bound(matrix.begin(), matrix.end(), target, 
                    [](vector<int> &vec, int tar){ return vec[0] < tar;});
        if( it != matrix.begin() && (*it)[0] > target
         || it == matrix.end() ) it--;
        return binary_search(it->begin(), it->end(), target);
    }
};

