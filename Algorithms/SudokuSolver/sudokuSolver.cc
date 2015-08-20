/*
copyright xu(xusiwei1236@163.com), all right reserved.

Sudoku Solver
==============

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

![before filled](http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
A sudoku puzzle...

![after filled](http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)
...and its solution numbers marked in red.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename Matrix>
void printMatrix(Matrix m);

class Solution {
    static const int kSize = 9;
    bool rowMask[kSize][kSize];
    bool colMask[kSize][kSize];
    bool areaMask[kSize][kSize];
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        memset(rowMask, false, sizeof(rowMask));
        memset(colMask, false, sizeof(colMask));
        memset(areaMask, false, sizeof(areaMask));
        
        // for each row.
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(!isdigit(board[r][c])) continue;
                
                int idx = board[r][c] - '1';
                int area = (r/3) * 3 + (c/3);
                if(rowMask[r][idx] || colMask[idx][c] || areaMask[area][idx]) {
                    return false;
                }
                
                rowMask[r][idx] = colMask[idx][c] = areaMask[area][idx] = true;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char> >& board, int r, int c) {
        if(r >= kSize) return true;
        if(c >= kSize) return solve(board, r+1, 0);
        if(isdigit(board[r][c])) return solve(board, r, c+1);
        
        // empty cell, select a num fill it.
        for(int idx = 0; idx < kSize; ++idx) {
            int area = (r/3) * 3 + (c/3);
            if(rowMask[r][idx] || colMask[idx][c] || areaMask[area][idx]) {
                continue;
            }
            
            // emplace idx + '1'
            board[r][c] = idx + '1';
            rowMask[r][idx] = colMask[idx][c] = areaMask[area][idx] = true;
            
//            printf("placed %d, %d  %c:\n", r, c, idx+'1'); printMatrix(board);
            
            // continous placing...
            if(solve(board, r, c+1)) return true;
            
            // can not continue to place, backtrack.
            board[r][c] = '.';
            rowMask[r][idx] = colMask[idx][c] = areaMask[area][idx] = false;
        }
        return false;
    }

    void solveSudoku(vector<vector<char> >& board) {
        if(!isValidSudoku(board)) return;
        solve(board, 0, 0);
    }
};

template<typename Matrix>
void printMatrix(Matrix m)
{
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++) {
            cout << m[i][j];
        }
        cout << "\n";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    vector<vector<char> > board;
    string row;
    
    while(cin >> row) {
        board.push_back(vector<char>(row.begin(), row.end()));
    }
    printMatrix(board);
    
    Solution().solveSudoku(board);
    printMatrix(board);
    
    return 0;
}
