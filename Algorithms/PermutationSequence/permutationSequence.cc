/*
copyright xu(xusiwei1236@163.com), all right reserved.

Permutation Sequence
=====================

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> P(n+1, 0); // permutation number table.
        P[0] = P[1] = 1;
        for(int i = 2; i <= n; i++) {
            P[i] = P[i-1] * i;
        }
        if(k > P[n]) return ""; // for invalid k.

        // now we stand on the root of a permutation tree.
        // we'll step down to the leaf node, that path is the result.
        // initial branches:
        vector<int> branches(n, 0);
        for(int i = 0; i < n; i++) {
            branches[i] = i+1;
        }

        k--;
        stringstream ss;
        for(int level = 0; level < n; level++) {
            int idx = k / P[n-1-level]; // index of branch.
            k %= P[n-1-level];
            ss << branches[idx]; // step down, path grow.
            branches.erase(branches.begin() + idx); // cut down the scaned branch.
        }

        return ss.str();
    }
};

int main(int argc, char* argv[])
{
    int n = 4, k = 6;
    if(argc > 1) n = atoi(argv[1]);
    if(argc > 2) k = atoi(argv[2]);
    printf("%s\n", Solution().getPermutation(n, k).c_str());
    return 0;
}
