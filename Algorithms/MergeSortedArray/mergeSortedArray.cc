/*
copyright xu(xusiwei1236@163.com), all right reserved.

Merge Sorted Array
===================

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        std::copy(B.begin(), B.begin()+n, A.begin()+m);
        std::inplace_merge(A.begin(), A.begin()+m, A.begin()+m+n);
    }
};
