/*
copyright xu(xusiwei1236@163.com), all right reserved.

Search in Rotated Sorted Array
===============================

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

#include <vector>
#include <iostream>
using namespace std;

#ifdef LINEAR

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0, sz = nums.size(); i < sz; ++i) {
            if(nums[i] == target) return i;
        }
        return -1;
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
    	int mid = low + (high - low)/2;
    	if(high < low) return -1;
    	if(A[low] <= A[mid]) { // [low, mid] is ordered.
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
    	return rotate_search(nums, 0, nums.size()-1, target);
    }
};

#endif

int main(int argc, char* argv[])
{
	int target = 0, n;
	vector<int> nums{4, 5, 6, 7, 0, 1, 2};
	
	for(int i: nums) {
		cout << Solution().search(nums, i) << ": " << i << endl;
	}
	return 0;
}
