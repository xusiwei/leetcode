/*
copyright xu(xusiwei1236@163.com), all right reserved.

Brick Wall
===========

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks. 


The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right. 


If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks. 

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks. 

Example:

Input: 
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
Explanation: 




Note:

The width sum of bricks in different rows are the same and won't exceed INT_MAX.
The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.
*/

#include <time.h>
#include <limits.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int> >& wall)
    {
        map<int, int> joints;
        for (auto& row : wall) {
            int pos = 0;
            for (int i = 0; i + 1 < row.size(); i++) {
                pos += row[i];
                ++joints[pos];
            }
        }

        int result = INT_MAX;
        const int N = static_cast<int>(wall.size());
        for (auto& p : joints) {
            result = min(result, N - p.second);
        }
        return result != INT_MAX ? result : N;
    }
};

vector<vector<int> > randomWall(int m, int n)
{
    vector<vector<int> > result;
    for (int i = 0; i < m; i++) {
        int last = 0;
        vector<int> row;
        int total = 0;
        for (int j = 1; j < n; j++) {
            if (rand() % 2) {
                int len = j - last;
                total += len;
                row.push_back(len);
                last = j;
            }
        }
        row.push_back(n - last);
        result.push_back(row);
    }
    return result;
}

void printMatrix(vector<vector<int> >& matrix)
{
    for (auto& row : matrix) {
        string buffer;
        cout << "{";
        for (auto& n : row) {
            cout << n << ",";
        }
        cout << "}" << endl;
    }
}

void printWall(vector<vector<int> >& wall)
{
    for (auto& row : wall) {
        string buffer;
        for (auto& width : row) {
            string brick(width * 3u, ' ');
            brick[0] = '|';
            string widstr = to_string(width);
            brick.replace((brick.size() - widstr.size()) / 2, widstr.size(), widstr);
            brick[brick.size() - 1] = '|';
            buffer += brick;
        }
        cout << buffer << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<vector<int> > wall = { { 1, 2, 2, 1 },
        { 3, 1, 2 },
        { 1, 3, 2 },
        { 2, 4 },
        { 3, 1, 2 },
        { 1, 3, 1, 1 } };
    int m = 0, n = 0;
    if (argc > 1) m = atoi(argv[1]);
    if (argc > 2) n = atoi(argv[2]);
    if (m && n) {
        srand(time(NULL));
        wall = randomWall(m, n);
    }

    printMatrix(wall);
    printWall(wall);
    cout << Solution().leastBricks(wall) << endl;
    return 0;
}
