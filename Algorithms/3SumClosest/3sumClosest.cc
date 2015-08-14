/*
copyright xu(xusiwei1236@163.com), all right reserved.

3Sum Closest
=================

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define trace printf

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MAX;
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0, sz = nums.size(); i < sz-1; ++i) {
            int front = i+1;
            int back = sz-1;
            
            // find: nums[front] + nums[back] == sum
            while(front < back) {
                int sum = nums[i] + nums[front] + nums[back];
                trace("# %d %d, %d %d\n", sum, result, abs(sum - target), abs(result - target));
                if(::abs(sum - target) < ::abs(result - target)) result = sum;
                if(sum < target) {
                    while(front < back && nums[front+1] == nums[front]) front++;
                    front++;
                }
                else if(sum > target) {
                    while(front < back && nums[back-1] == nums[back]) back--;
                    back--;
                }
                else return sum;
            }

            // for duplicate Number 1.
            while(i+1 < sz && nums[i+1] == nums[i]) i++;
        }
        return result;
    }
};

int main()
{
	vector<int> nums;
	
	int n, target;
	
	cin >> target;
	while(cin >> n) {
		nums.push_back(n);
	}
	
	cout << Solution().threeSumClosest(nums, target) << endl;
	return 0;
}
