/*
copyright xu(xusiwei1236@163.com), all right reserved.

Number of Islands
==================

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110110101100000000
Answer: 1
Example 2:
11000110000010000011
Answer: 3

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <vector>
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
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        UnionFind uf(m*n+1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (j+1 <  n && grid[i][j+1] == '1') uf.connect(i*n + j, i*n + (j+1));
                    if (j-1 >= 0 && grid[i][j-1] == '1') uf.connect(i*n + j, i*n + (j-1));
                    if (i+1 <  m && grid[i+1][j] == '1') uf.connect(i*n + j, (i+1)*n + j);
                    if (i-1 >= 0 && grid[i-1][j] == '1') uf.connect(i*n + j, (i-1)*n + j);
                } else {
                    uf.connect(i*n + j, n*m);
                }
            }
        }
        return uf.count()-1;
    }
};

int main(int argc, char* argv[])
{
    int n = 3;
    int m = 4;
    if (argc > 1) n = atoi(argv[1]);
    if (argc > 2) m = atoi(argv[2]);

    vector<vector<char>> grid;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vector<char> v;
        for (int j = 0; j < m; j++) {
            v.push_back(rand()%2 ? '1' : '0');
            cout << v.back() << " ";
        }
        cout << endl;
        grid.push_back(v);
    }

    cout << Solution().numIslands(grid) << endl;
    return 0;
}
