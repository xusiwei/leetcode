/*
copyright xu(xusiwei1236@163.com), all right reserved.

Surrounded Regions
===================

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



For example,

X X X X
X O O X
X X O X
X O X X




After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
using namespace std;

class UnionFind {
    int  count_;  // number of components
    int* rank_;   // to limits tree hights 
    int* id_;     // id[i] parent of i
public:
    UnionFind(int n) {
        count_ = n;
        rank_ = new int[n];
        id_ = new int[n];
        for (int i = 0; i < n; i++) {
            id_[i] = i;
            rank_[i] = 0;
        }
    }
    
    ~UnionFind() {
        delete [] rank_;
        delete [] id_;
    }
    
    int count() { return count_; }
    
    int find(int p) {
        while (p != id_[p])    {
            id_[p] = id_[id_[p]]; // path compression
            p = id_[p];
        }
        return p;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    void connect(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (rank_[i] < rank_[j]) id_[i] = j;
        else if (rank_[i] > rank_[j]) id_[j] = i;
        else { // ==
            id_[j] = i;
            rank_[i]++;
        }
        count_--;
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        UnionFind uf(n*m+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) { // side case, connect to dummy node
                    uf.connect(i*m + j, n*m);
                    continue;
                }
                char c = board[i][j]; // inner case, connect to same neighbor
                if (board[i+1][j] == c) uf.connect((i+1)*m + j, i*m + j);
                if (board[i-1][j] == c) uf.connect((i-1)*m + j, i*m + j);
                if (board[i][j+1] == c) uf.connect(i*m + (j+1), i*m + j);
                if (board[i][j-1] == c) uf.connect(i*m + (j-1), i*m + j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!uf.connected(i*m + j, n*m)) {
                    board[i][j] = 'X';
                }    
            }
        }
    }
};

#if 0
#define trace printf

// TLE
// BFS only
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();

        const int dx[] = {0, 1,  0, -1};
        const int dy[] = {1, 0, -1,  0};

        #define onside(x, y) ((x) == 0 || (x) == row-1 || (y) == 0 || (y) == col-1)
        #define onboard(x, y) (0 <= (x) && (x) < row   && 0 <= (y) && (y) < col)

        vector<vector<bool>> mark;
        for (int i = 0; i < row; i++) {
            mark.push_back(vector<bool>(col, false));
        }

        queue<pair<int, int>> candidates;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] != 'X') {
                    trace("candi: %d, %d\n", i, j);    
                    candidates.push(make_pair(i, j));
                }
            }
        }

        while (candidates.size() > 0) {
            queue<pair<int, int>> q;
            while (candidates.size() > 0) {
                int x = candidates.front().first;
                int y = candidates.front().second;
                candidates.pop();

                if (!mark[x][y]) {
                    trace("\npick: %d, %d\n", x, y);
                    q.push(make_pair(x, y));
                    break;
                }
            }

            bool sidecase = false;
            vector<pair<int, int>> current; // for current region
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                current.push_back(make_pair(x, y));
                if (onside(x, y)) sidecase = true;
                trace("mark %d, %d\n", x, y);
                mark[x][y] = true;
            
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (onboard(nx, ny) && !mark[nx][ny] && board[nx][ny] != 'X') {
                        trace("   push %d, %d\n", nx, ny);
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            if (!sidecase) {
                for (auto pt : current) {
                    trace("flipping %d, %d\n", pt.first, pt.second);
                    board[pt.first][pt.second] = 'X';
                }
            }
        }
    }
};
#endif

template <typename Matrix>
void printMatrix(const Matrix& m)
{
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<vector<char>> board;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        char c;
        vector<char> row;
        while (ss >> c) {
            row.push_back(c);
        }
        board.push_back(row);
    }

    cout << "before flipping:\n";
    printMatrix(board);

    Solution().solve(board);
    
    cout << "after flipping:\n";
    printMatrix(board);
    return 0;
}
