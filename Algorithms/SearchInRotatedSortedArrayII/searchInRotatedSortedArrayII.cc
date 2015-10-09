/*
copyright xu(xusiwei1236@163.com), all right reserved.

Search in Rotated Sorted Array II
==================================

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

*/

#include <vector>
#include <iostream>
using namespace std;

#ifdef LINEAR

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find(nums.begin(), nums.end(), target) != nums.end();
    }
};

#else // LINEAR

class Solution {
public:
    static int binary_search(vector<int>& A, int low, int high, int target) {
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(A[mid] == target) return mid;
            else if(A[mid] > target) {
                high = mid-1;
            }
            else { // if(A[mid] < target)
                low = mid+1;
            }
        }
        return -1;
    }
    
    static int rotate_search(vector<int>& A, int low, int high, int target) {
        if(high < low) return -1;
        
        int mid = low + (high - low)/2;
        if(A[mid] == target) return mid;
        
        if(A[low] == A[mid] || A[mid] == A[high]) { // duplicates.
            while(A[low] == A[mid]) low++;   // skip
            while(A[high] == A[mid]) high--; // skip
            return rotate_search(A, low, high, target);
        }
        
        if(A[low] < A[mid]) { // [low, mid] is ordered.
            if(A[low] <= target && target <= A[mid]) { // target in left half.
                return binary_search(A, low, mid, target);
            }
            else { // target in right half.
                return rotate_search(A, mid+1, high, target);
            }
        }
        else { // [mid+1, high] is oredered.
            if(A[mid+1] <= target && target <= A[high]) { // target in right.
                return binary_search(A, mid+1, high, target);
            }
            else { // in left.
                return rotate_search(A, low, mid, target);
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return rotate_search(nums, 0, nums.size()-1, target) >= 0;
    }
};

#endif

int main(int argc, char* argv[])
{
    return 0;

