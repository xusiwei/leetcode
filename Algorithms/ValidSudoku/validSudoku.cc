/*
copyright xu(xusiwei1236@163.com), all right reserved.

Valid Sudoku
=============

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define getbit(reg, bit) reg &  (1 << (bit))

#ifdef DEBUG
#define setbit(reg, bit) printf("set %d to %04x, @ %d, %d at %d\n", bit, reg, r, c, __LINE__); reg |= (1 << (bit))
#else // DEBUG
#define setbit(reg, bit) reg |= (1 << (bit))
#endif // DEBUG

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        unsigned rowMask[9] = {0};
        unsigned colMask[9] = {0};
        unsigned subMask[9] = {0};
        // for each row.
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                char ch = board[r][c];
                if(!isdigit(ch)) continue;
                int idx = board[r][c] - '0' - 1;
                
                if(getbit(rowMask[r], idx)) return false;
                setbit(rowMask[r], idx);
                
                if(getbit(colMask[idx], c)) return false;
                setbit(colMask[idx], c);
                
                int subId = (r/3) * 3 + (c/3);
                if(getbit(subMask[subId], idx)) return false;
                setbit(subMask[subId], idx);
            }
        }
        return true;
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
	
	cout << boolalpha << Solution().isValidSudoku(board) << endl;
	
	return 0;
}
