/*
copyright xu(xusiwei1236@163.com), all right reserved.

Maximum Product Subarray
=========================

Find the contiguous subarray within an array (containing at least one number) which has the largest product.



For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(vector<int>& A) {
        // define p(i, j) := A[i]*A[i+1]*...*A[j]
        // according to definition, mp(A) := max({ p(i, j) | 0 <= i <= j < n })
        // define m(i) := mp(A[0...i])
        // if all of A[i] >= 0, m(i) = max(m[i-1]*A[i], A[i])
        if (A.size() == 0) return 0;
        if (A.size() == 1) return A[0];
        int ppm = 0, npm = 0, m = 0;
        for (int i = 0; i < A.size(); i++){
            if (A[i] < 0) swap(ppm, npm);
            ppm = max(ppm * A[i], A[i]);
            npm = min(npm * A[i], A[i]);
            m = max(m, ppm);
        }
        return m;
    }
};
