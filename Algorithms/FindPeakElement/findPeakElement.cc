/*
copyright xu(xusiwei1236@163.com), all right reserved.

Find Peak Element
==================

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int findPeak(vector<int>& A, int i, int j) {
        if (i > j) return -2;

        int m = i + (j-i)/2;
        if ((m == 0          || A[m-1] < A[m])
         && (m == A.size()-1 || A[m+1] < A[m])) {
            return m;
        }
        if (j-i == 0) return -1;

        int left  = findPeak(A, i, m);
        if (left >= 0) return left;

        return findPeak(A, m+1, j);
    }

    int findPeakElement(vector<int>& A) {
        int n = A.size();
        if (n == 0) return -1;
        if (n == 1) return 0;

        return findPeak(A, 0, n-1);
    }
};

// navie way
class Solution0 {
public:
    int findPeakElement(vector<int>& A) {
        int n = A.size();
        if (n == 0) return -1;
        if (n == 1) return 0;

        for (int i = 0; i < n; i++) {
            if ((i == 0   || A[i-1] < A[i])
             && (i == n-1 || A[i+1] < A[i])) {
               return i;
            }
        }
        return -1;
    }
};

unordered_set<int> findAllPeak(vector<int>& A) {
    unordered_set<int> peaks;
    int n = A.size();
    if (n == 0) return peaks;
    if (n == 1) {
        peaks.insert(0);
        return peaks;
    }

    for (int i = 0; i < n; i++) {
        if ((i == 0   || A[i-1] < A[i])
         && (i == n-1 || A[i+1] < A[i])) {
            peaks.insert(i);
        }
    }
    return peaks;
}

int main(int argc, char* argv[])
{
    int n = 10;
    vector<int> v;
    if (argc > 1) n = atoi(argv[1]);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v.push_back(random() % n);
        cout << v[i] << ", ";
    }
    cout << endl;

    unordered_set<int> ps = findAllPeak(v);

    int p1 = Solution().findPeakElement(v);
    int p2 = Solution0().findPeakElement(v);
    cout << p1 << ": " << ps.count(p1) << endl;
    cout << p2 << ": " << ps.count(p2) << endl;
    return 0;
}
