/*
copyright xu(xusiwei1236@163.com), all right reserved.

Reshape the Matrix
===================

In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.



You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

 The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.



If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.


Example 1:

Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.



Example 2:

Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.



Note:

The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c)
    {
        const size_t N = nums.size();
        const size_t M = nums[0].size();
        if (r * c > N * M || N == 0) return nums;

        size_t count = 0;
        vector<int> row(c, 0);
        vector<vector<int> > result(r, row);
        for (size_t i = 0; i < r; i++) {
            for (size_t j = 0; j < c; j++) {
                result[i][j] = nums[count / M][count % M];
                count++;
            }
        }
        return result;
    }
};

void printMatrix(vector<vector<int> >& matrix)
{
    for (auto& v : matrix) {
        for (int& i : v) {
            cout << i << "\t";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    int r = 1, c = 4, m = 0, n = 0;
    vector<vector<int> > matrix = { { 1, 2 }, { 3, 4 } };

    if (argc > 1) r = atoi(argv[1]);
    if (argc > 2) c = atoi(argv[2]);
    if (argc > 3) m = atoi(argv[3]);
    if (argc > 4) n = atoi(argv[4]);

    if (m && n) {
        matrix.clear();
        int count = 0;
        for (int i = 0; i < m; i++) {
            vector<int> row;
            for (int j = 0; j < n; j++) {
                row.push_back(++count);
            }
            matrix.push_back(row);
        }
    }

    cout << "matrix:\n";
    printMatrix(matrix);

    auto result = Solution().matrixReshape(matrix, r, c);

    cout << "result:\n";
    printMatrix(result);
    return 0;
}
