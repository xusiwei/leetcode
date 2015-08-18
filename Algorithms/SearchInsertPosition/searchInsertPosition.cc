/*
copyright xu(xusiwei1236@163.com), all right reserved.

Search Insert Position
=======================

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 
*/

class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int mid, low = 0, high = A.size()-1;
        
        while(low <= high) {
            mid = low + (high - low)/2;
            if(A[mid] < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};
