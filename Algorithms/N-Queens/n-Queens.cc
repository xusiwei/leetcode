/*
copyright xu(xusiwei1236@163.com), all right reserved.

N-Queens
=========

The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    int n;
public:
    void solve(vector<vector<string>>& res, vector<int>& cur) {
        int iq = static_cast<int>(cur.size()) - 1;
        for(int i = 0; i < iq; i++) {
            if(cur[i] == cur[iq]
            || abs(i - iq) == abs(cur[i] - cur[iq])) return;
        }

        if(iq == n-1) {
            vector<string> ans;
            for(int i = 0; i < n; i++) {
                string row(n, '.');
                row[cur[i]] = 'Q';
                ans.push_back(row);
            }
            res.push_back(ans);
        }

        for(int i = 0; i < n; i++) {
            cur.push_back(i);
            solve(res, cur);
            cur.pop_back(); // backtrack
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cur;
        this->n = n;
        solve(res, cur);
        return res;
    }
};


template<typename Matrix>
void printMatrix(Matrix m)
{
    for(int i = 0, isz = m.size(); i < isz; i++) {
        cout << "answer " << i << ": \n";
        for(int j = 0, jsz = m[i].size(); j < jsz; j++) {
            cout << m[i][j] << "\n";
        }
        cout << "\n";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int n = 4;
    if(argc > 1) n = atoi(argv[1]);
    printMatrix(Solution().solveNQueens(n));
    return 0;
}
