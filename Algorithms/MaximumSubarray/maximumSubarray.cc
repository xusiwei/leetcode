/*
copyright xu(xusiwei1236@163.com), all right reserved.

Maximum Subarray
=================

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/
#include <limits.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#ifdef DNC
class Solution {
public:
    // divide an conquer
    int dnc(int* A, int n) {
        if(n == 0) return INT_MIN;
        if(n == 1) return A[0];
        int mid = n/2;
        // [0, mid), [mid, n-mid)
        int ans = max(dnc(A, mid), dnc(A+mid, n-mid));
        int now = A[mid-1], may = now;
        for(int i = mid-2; i >= 0; i--) {
            now += A[i];
            may = max(may, now);
        }
        now = may;
        for(int i = mid; i < n; i++) {
            now += A[i];
            may = max(may, now);
        }
        return max(ans, may);
    }

    int maxSubArray(vector<int>& num) {
        return dnc(&num[0], num.size());
    }
};
#else // DNC
class Solution {
public:
    int maxSubArray(vector<int>& num) {
        int sum = num[0], ans = num[0];
        int minSum = num[0];
        for(int i = 0; i < num.size(); i++) {
            sum += num[i];
            ans = max(ans, sum - minSum);
            minSum = min(minSum, sum);
        }
        return ans;
    }
};
#endif

int main(int argc, char* argv[])
{
    vector<int> vec{-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(vec) << endl;
    return 0;
}
