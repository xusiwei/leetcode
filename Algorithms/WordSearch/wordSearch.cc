/*
copyright xu(xusiwei1236@163.com), all right reserved.

Word Search
============

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool backtrack(vector<vector<char> >& board, string& word, vector<vector<bool> >& mask, int idx, int r, int c) {
        if( !mask[r][c] && board[r][c] == word[idx] ) {
            mask[r][c] = true;
            if(++idx == word.size()) return true;
            
            // try neighbors.
            if( r+1 < board.size()    && backtrack(board, word, mask, idx, r+1, c)
             || c+1 < board[0].size() && backtrack(board, word, mask, idx, r, c+1)
             || r-1 >= 0              && backtrack(board, word, mask, idx, r-1, c)
             || c-1 >= 0              && backtrack(board, word, mask, idx, r, c-1) ) {
                return true;
            }
            
            mask[r][c] = false; // backtrack.
        }
        
        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int row = board.size();
        if(row == 0) return word.length() == 0;
        int col = board[0].size();
        
        vector<vector<bool> > mask(row, vector<bool>(col, false));
        int idx = 0;
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(board[r][c] == word[0]) {
                    if(backtrack(board, word, mask, idx, r, c)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

vector<vector<char> > buildBoard(string* input, int num) {
    vector<vector<char> > board;
    for(int r = 0; r < num; r++) {
        vector<char> row;
        for(int c = 0; c < input[0].length(); c++) {
            row.push_back(input[r][c]);
        }
        board.push_back(row);
    }
    return board;
}

int main(int argc, char* argv[])
{
    string word = "SEEEEE";
    string temp[] = {
        "ABCEEE",
        "ABCEEE",
        "ABCEEE",
        "SFCSSE",
        "ADEESE"
    };
    string *input = temp;
    int num = sizeof(temp)/sizeof(temp[0]);
    vector<string> vars;
    
    if(argc > 2) {
        word = argv[1];
        for(int i = 2; i < argc; i++) {
            vars.push_back(argv[i]);
        }
        input = &vars[0];
    }
    
    vector<vector<char> > board = buildBoard(input, num);
    cout << boolalpha << Solution().exist(board, word) << endl;
    return 0;
}
