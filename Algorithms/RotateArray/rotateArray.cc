/*
copyright xu(xusiwei1236@163.com), all right reserved.

Rotate Array
=============

Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]. 

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.


[show hint]
Hint:
Could you do it in-place with O(1) extra space?
*/

class Solution {
public:
    void reverse(vector<int>& A, int b, int e) {
        for (e--; b < e; b++, e--) {
            int t = A[b];
            A[b] = A[e];
            A[e] = t;
        }
    }

    void rotate(vector<int>& A, int k) {
        const int N = A.size();
        if (N <= 1 || k == 0) return;
        k %= N;
        reverse(A, 0, N-k);
        reverse(A, N-k, N);
        reverse(A, 0, N);
    }
};
