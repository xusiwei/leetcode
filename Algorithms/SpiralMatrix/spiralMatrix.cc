/*
copyright xu(xusiwei1236@163.com), all right reserved.

Spiral Matrix
==============

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() < 1) return result;
        int row = matrix.size(), col = matrix[0].size();
        if(row == 1) return matrix[0];
        if(col == 1) {
            for(auto& v: matrix) result.push_back(v[0]);
            return result;
        }
        
        int x = 0, y = 0;
        int sx = row-1, sy = col-1;
        int dx[4] = {0, 1,  0, -1};
        int dy[4] = {1, 0, -1,  0};
        int di = 0;
        
        int n = row*col;
        while(n--) {
            result.push_back(matrix[x][y]);
            if(x == sx && (di&1) ) { // (di == 1 || di == 3)
                sx = row-1 - sx + (di == 1 ? dx[di] : 0);
                di = (di+1)%4;
            }
            if(y == sy && !(di&1) ) { // (di == 0 || di == 2)
                sy = col-1 - sy + (di == 2 ? dy[di] : 0);
                di = (di+1)%4;
            }
            x += dx[di];
            y += dy[di];
        }
        return result;
    }
};

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
    for(int i = 0, isz = m.size(); i < isz; i++) {
        printVector(m[i]);
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    int row = 3, col = 3;
    if(argc > 1) row = atoi(argv[1]);
    if(argc > 2) col = atoi(argv[2]);
    
    vector<vector<int>> matrix;
    for(int i = 0; i < row; i++) {
        vector<int> v;
        for(int j = 0; j < col; j++) {
            v.push_back(col*i + j + 1);
        }
        matrix.push_back(v);
    }
    printMatrix(matrix);
    printVector(Solution().spiralOrder(matrix));
    cout << endl;
    return 0;
}
