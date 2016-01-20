/*
copyright xu(xusiwei1236@163.com), all right reserved.

Maximal Rectangle
==================

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        
        vector<vector<int> > H(row, vector<int>(col));
        for (int c = 0; c < col; c++) {
            H[0][c] = (matrix[0][c] == '0' ? 0 : 1);
        }
        int maxRect = largestRectangleArea(H[0]);
        for (int r = 1; r < row; r++) {
            for (int c = 0; c < col; c++) {
                H[r][c] = (matrix[r][c] == '0' ? 0 : 1 + H[r - 1][c]);
            }
            int area = largestRectangleArea(H[r]);
            if (area > maxRect) {
                maxRect = area;
            }
        }
        return maxRect;
    }
    
    // invariant:
    //   if L is the left index of largest rectangle, then H[L-1] < H[L] (L > 0)
    // because, if H[L-1] >= H[L], area[L-1:R] > area[L:R]
    int largestRectangleArea(vector<int>& H) {
        if (H.size() == 0) return 0;
        stack<int> candidates; // left side candidates.
        
        H.push_back(0);
        int maxArea = 0;
        for (int i = 0; i < H.size(); i++) {
            if (candidates.empty() || H[i] >= H[candidates.top()]) {
                candidates.push(i);
                continue;
            }
                int top = candidates.top();
                candidates.pop();
                int area = H[top] * (candidates.empty() ? i : i - candidates.top() - 1);
                if (area > maxArea) {
                    maxArea = area;
                }
                i--;
        }
        
        return maxArea;
    }
};


template <class Matrix>
void printMatrix(Matrix mat);


int main(int argc, char* argv[])
{
    vector<vector<char> > matrix;

    string line;
    while (getline(cin, line)) {
        vector<char> row(line.begin(), line.end());
        matrix.push_back(row);
    }
    
    printMatrix(matrix);
    cout << "maximal rectangle:" << Solution().maximalRectangle(matrix) << endl;
    return 0;
}

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

