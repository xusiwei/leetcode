/*
copyright xu(xusiwei1236@163.com), all right reserved.

Kth Largest Element in an Array
================================

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.


Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        k = A.size() - k; // (k > A.size() ? k % A.size() : k);
        nth_element(A.begin(), A.begin() + k, A.end());
        return A[k];
    }
};