/*
copyright xu(xusiwei1236@163.com), all right reserved.

Unique Binary Search Trees
===========================

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        static int cached[64] = {1, 1, 2, 5};
        if(cached[n]) return cached[n];
        
        int result = 0;
        //   root 
        //   /  \
        // LST  RST
        // LST: left sub tree
        // RST: right sub tree
        for(int i=0; i<n; i++) { // for each size of left subtree
            result += numTrees(i)*numTrees(n-1-i);
        }
        return cached[n] = result;
    }
};

int main(int argc, char* argv[])
{
    for(int i = 0, n = 1; n > 0; i++) {
        n = Solution().numTrees(i);
        cout << i << ": " << n << endl;
    }
    return 0;
}
