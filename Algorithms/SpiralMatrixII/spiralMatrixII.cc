/*
copyright xu(xusiwei1236@163.com), all right reserved.

Spiral Matrix II
=================

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int x = 0, y = 0;
        int sx = n-1, sy = n-1;
        int dx[4] = {0, 1,  0, -1};
        int dy[4] = {1, 0, -1,  0};
        int di = 0;
        
        for(int i = 1, sz = n*n; i <= sz; i++) {
            result[x][y] = i;
            if(x == sx && (di&1) ) { // (di == 1 || di == 3)
                sx = n-1 - sx + (di == 1 ? dx[di] : 0);
                di = (di+1)%4;
            }
            if(y == sy && !(di&1) ) { // (di == 0 || di == 2)
                sy = n-1 - sy + (di == 2 ? dy[di] : 0);
                di = (di+1)%4;
            }
            x += dx[di];
            y += dy[di];
        }
        return result;
    }
};
