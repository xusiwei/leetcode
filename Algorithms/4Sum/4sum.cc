/*
copyright xu(xusiwei1236@163.com), all right reserved.

4Sum
======

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
	static void sort4(int& a, int& b, int& c, int& d) {
		int tmp[4];
		if(a > b) std::swap(a, b);
		if(c > d) std::swap(c, d);
		
		if(a < c) {
			tmp[0] = a;
			tmp[1] = b < c ? b : c;
		}
		else {
			
		}
	}
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        multimap<int, tuple<int, int>> dict;
		
		sort(nums.begin(), nums.end());
        for(int i = 0, sz = nums.size(); i < sz-1; i++) {
			for(int j = i - 1; j < sz; j++) {
				int c = nums[i];
				int d = nums[j];
				int sum = c + d;
				
				auto it = dict.find(-sum);
				if(it != dict.end()) {
					for(; it->first + sum == 0; ++it) {
						int a = std::get<0>(it->second);
						int b = std::get<1>(it->second);
						
					}
				}
				else {
					dict[sum] = make_tuple(c, d);
				}
			}
		}
        
        return result;
    }
};