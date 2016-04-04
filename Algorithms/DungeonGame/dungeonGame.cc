/*
copyright xu(xusiwei1236@163.com), all right reserved.

Dungeon Game
=============

table.dungeon, .dungeon th, .dungeon td {
  border:3px solid black;
}

 .dungeon th, .dungeon td {
    text-align: center;
    height: 70px;
    width: 70px;
}


The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess. 
The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately. 
Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step. 


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.
For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.


 
-2 (K) 
-3 
3 
 
 
-5 
-10 
1 
 
 
10 
30 
-5 (P) 
 




Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.  



Credits:Special thanks to @stellari for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& D) {
        const int N = D.size();
        if (N == 0) return 0;
        
        const int M = D[0].size();
        vector<int> H(M, 0);
        for (int i = N-1; i >= 0; i--) {
            for (int j = M-1; j >= 0; j--) {
                if (i+1 == N && j+1 == M) {
                    H[j] = max(1 + -D[i][j], 1);
                } else if (i+1 == N) {
                    H[j] = max(H[j+1] + -D[i][j], 1);
                } else if (j+1 == M) {
                    H[j] = max(H[j] + -D[i][j], 1);
                } else {
                    H[j] = max(min(H[j+1], H[j]) + -D[i][j], 1);
                }
            }
        }
        return H[0];
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> D{{-2,-3,3}, {-5,-10,1}, {10,30,-5}};
    
    if (argc > 2) {
        D.clear();
        srand(time(NULL));
        int N = atoi(argv[1]);
        int M = atoi(argv[2]);
        for (int i = 0; i < N; i++) {
            vector<int> v(M);
            for (int j = 0; j < M; j++) {
                v[j] = rand() % (M*N) - (M*N)/2;
            }
            D.push_back(v);
        }
    }
    
    for (int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D[i].size(); j++) {
            cout << D[i][j] << "\t";
        }
        cout << "\n";
    }
    
    cout << "minimum health: " << Solution().calculateMinimumHP(D) << endl;
    return 0;
}
