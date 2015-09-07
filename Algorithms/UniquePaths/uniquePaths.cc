/*
copyright xu(xusiwei1236@163.com), all right reserved.

Unique Paths
=============

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        static int tab[100][100] = {0};
        if(tab[m][n]) return tab[m][n];
        if(1 == m || 1 == n) return tab[m][n] = 1;
        return tab[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};
