/*
copyright xu(xusiwei1236@163.com), all right reserved.

First Missing Positive
=======================

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int len = A.size();
        for(int i = 0; i < len; ++i) {
            // go ahead to makes, A[i] == i+1  <=> A[i]-1 == i <=> A[A[i]-1] == A[i]
            while(A[i] > 0 && A[i]-1 < len && A[A[i]-1] != A[i]) {
                swap(A[i], A[A[i]-1]);
            }
        }
        
        // A[0] == 1, A[1] == 2, ... A[k] == k+1
        for(int i = 0; i < len; ++i) {
            if(A[i] != i+1) return i+1;
        }
        return len+1;
    }
};

