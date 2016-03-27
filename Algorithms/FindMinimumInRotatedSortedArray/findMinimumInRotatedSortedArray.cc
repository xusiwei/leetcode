/*
copyright xu(xusiwei1236@163.com), all right reserved.

Find Minimum in Rotated Sorted Array
=====================================

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
#include <limits.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMinHelper(vector<int>& A, int i, int j) {
        int m = i + (j-i)/2;

        if (i > j) return INT_MAX;
        if (i == j) return A[i];
        if (i+1 == j) return min(A[i], A[j]);

        if (A[i] < A[m]) { // A[i...m] is ordered, search in [m...j] and maybe A[i]
            return min(findMinHelper(A, m, j), A[i]);
        }
        return min(findMinHelper(A, i, m), A[j]);
    }

    int findMin(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        if (n == 1) return A[0];

        return findMinHelper(A, 0, n-1);
    }
};

int main(int argc, char* argv[])
{
    int n = 20;
    vector<int> v;

    srand(time(NULL));
    if (argc > 1) n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }

    int pivot = rand() % n;
    std::rotate(v.begin(), v.begin() + pivot, v.end());
    std::for_each(v.begin(), v.end(), [](int i) { cout << i << ","; });
    cout << endl;

    cout << Solution().findMin(v) << endl;
    return 0;
}
