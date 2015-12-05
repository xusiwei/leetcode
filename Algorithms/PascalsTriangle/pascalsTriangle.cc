/*
copyright xu(xusiwei1236@163.com), all right reserved.

Pascal's Triangle
==================

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int nRows) {
        vector<vector<int> > result;
        for (int n = 0; n < nRows; ++n) {
            vector<int> row(n+1, 0);
            row[0] = row[n] = 1;
            for (int m = 1; m < n; ++m) {
                row[m] = (m == 1 || m == n-1) ? n
                    : (result[n-1][m-1] + result[n-1][m]);
            }
            result.push_back(row);
        }
        return result;
    }
};

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

int main(int argc, char* argv[])
{
    int n = 5;
    if (argc > 1) n = atoi(argv[1]);
    printMatrix(Solution().generate(n));
    return 0;
}
