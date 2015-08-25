/*
copyright xu(xusiwei1236@163.com), all right reserved.

Rotate Image
=============

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> result(col, vector<int>(row, 0));
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                result[c][row-1-r] = matrix[r][c];
            }
        }
        matrix.swap(result);
    }
};