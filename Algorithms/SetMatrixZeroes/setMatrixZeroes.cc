/*
copyright xu(xusiwei1236@163.com), all right reserved.

Set Matrix Zeroes
==================

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return ;
        int col = matrix[0].size();
        
        vector<int> zRows;
        vector<int> zCols;
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(matrix[r][c] == 0) {
                    zRows.push_back(r);
                    zCols.push_back(c);
                }
            }
        }
        
        for(int i = 0; i < zRows.size(); i++) {
            for(int c = 0; c < col; c++) {
                matrix[zRows[i]][c] = 0;
            }
        }
        
        for(int i = 0; i < zCols.size(); i++) {
            for(int r = 0; r < row; r++) {
                matrix[r][zCols[i]] = 0;
            }
        }
    }
};

