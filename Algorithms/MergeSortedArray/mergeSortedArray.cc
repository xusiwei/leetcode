/*
copyright xu(xusiwei1236@163.com), all right reserved.

Merge Sorted Array
===================

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
#ifdef STD
        std::copy(B.begin(), B.begin()+n, A.begin()+m);
        std::inplace_merge(A.begin(), A.begin()+m, A.begin()+m+n);
#else
        // inplace merge
        // key point: reorder scan
        int i = m - 1, j = n - 1, k = m+n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) A[k--] = A[i--];
            else A[k--] = B[j--];
        }
        while (i >= 0) A[k--] = A[i--];
        while (j >= 0) A[k--] = B[j--];
#endif
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

int main(int argc, char* argv[]) {
    int m = 6, n = 4;
    vector<int> A, B;

    srand(time(NULL));
    if (argc > 1) m = atoi(argv[1]);
    if (argc > 2) n = atoi(argv[2]);

    for (int i = 0; i < m; i++) {
        A.push_back(rand() % (m+n) * 2);
    }
    for (int i = 0; i < n; i++) {
        B.push_back(rand() % (m+n));
    }

    sort(A.begin(), A.end()); printVector(A);
    sort(B.begin(), B.end()); printVector(B);
    A.resize(A.size() + B.size());

    Solution().merge(A, m, B, n);
    printVector(A);

    return 0;
}
