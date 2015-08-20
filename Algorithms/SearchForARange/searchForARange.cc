/*
copyright xu(xusiwei1236@163.com), all right reserved.

Search for a Range
===================

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#ifdef STD

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        
        auto low = lower_bound(nums.begin(), nums.end(), target);
        
        if(low == nums.end() || *low != target) {
            result.push_back(-1);
            result.push_back(-1);
        }
        else {
            result.push_back(low == nums.end() ? -1 : low - nums.begin());
            result.push_back(upper_bound(nums.begin(), nums.end(), target)-1-nums.begin());
        }
        
        return result;
    }
};

#else // STD

class Solution {
public:
    static int lowerBound(vector<int>& A, int target) {
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
    
    static int upperBound(vector<int>& A, int low, int high, int target) {        
        int mid;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(A[mid] > target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return high;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        
        int low = lowerBound(nums, target);
        if(nums[low] != target) {
            result.push_back(-1);
            result.push_back(-1);
        }
        else {
            result.push_back(low);
            result.push_back(upperBound(nums, low, nums.size()-1, target));
        }
        
        return result;
    }
};

#endif // STD

template<typename Vector>
void printVector(Vector v)
{
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "\n" : " ");
    }
}
#define PrintVector(v) cout << #v << ": "; printVector((v))

int main(int argc, char* argv[])
{
    int target, n;
    vector<int> nums;
    
    cin >> target;
    while(cin >> n) {
        nums.push_back(n);
    }
    PrintVector(nums);
    
    PrintVector(Solution().searchRange(nums, target));
    return 0;
}
