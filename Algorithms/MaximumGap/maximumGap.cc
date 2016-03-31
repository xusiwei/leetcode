/*
copyright xu(xusiwei1236@163.com), all right reserved.

Maximum Gap
============

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:Special thanks to @porker2008 for adding this problem and creating all test cases.
*/
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& A) {
        if (A.size() < 2) return 0;
        sort(A.begin(), A.end());

        int maxGap = INT_MIN;
        for (int i = 0; i < A.size()-1; i++) {
            maxGap = max(maxGap, A[i+1] - A[i]);
        }
        return maxGap;
    }
};

int main(int argc, char* argv[])
{
    int n = 10;
    if (argc > 1) n = atoi(argv[1]);

    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % n);
    }
    cout << Solution().maximumGap(v) << endl;
    return 0;
}
