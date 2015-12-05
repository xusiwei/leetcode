/*
copyright xu(xusiwei1236@163.com), all right reserved.

Pascal's Triangle II
=====================

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> row(n+1, 0);
        row[0] = row[n] = 1;
        if (n < 2) return row;
        row[1] = row[n-1] = n;
        for (int m = 2; m < n-1; ++m) {
            // C(m, n)   = n*(n-1)*...*(n-m+2)*(n-m+1) / m*(m-1)!
            // C(m-1, n) = n*(n-1)*...*(n-m+2) / (m-1)!
            // => C(m, n) = C(m-1, n) * ( (n-m+1) / m )
            row[m] = row[m-1] * (long long)(n-m+1) / m;
        }
        return row;
    }
};

template <typename Vector>
void printVector(Vector &v, string sep = ",") {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << (i+1 == v.size() ? "]" : sep);
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    int n = 6;
    if (argc > 1) n = atoi(argv[1]);
    vector<int> v = Solution().getRow(n);
    printVector(v);
    return 0;
}

