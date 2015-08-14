/*
3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

#ifdef DEBUG
#define trace printf
#else
#define trace
#endif

#if 0

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<string> dict;
        vector<vector<int>> result;
        
        multimap<int, tuple<int, int>> buf;
        for(int i = 0, sz = nums.size(); i < sz-1; ++i) {
            auto it = buf.find(-nums[i]);
            if(it != buf.end()) {
                for(; it->first + nums[i] == 0; it++) {
                    int a = std::get<0>(it->second);
                    int b = std::get<1>(it->second);
                    
                    multiset<int> t{nums[a], nums[b], nums[i]};
                
                    string s;
                    for(int n: t) s = s + (n + " ");
                    
                    auto pos = dict.find(s);
                    if(pos == dict.end()) {
                        dict.insert(pos, s);
                        result.push_back(vector<int>(t.begin(), t.end()));
                    }
                }
            }
            for(int j = i + 1; j < sz; ++j) {
                int sum = nums[i] + nums[j];
                buf[sum] = make_tuple(i, j);
            }
        }
        return result;
    }
};

#else

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        std::sort(nums.begin(), nums.end());
        for(int i = 0, sz = nums.size(); i < sz-1; ++i) {
            int target = -nums[i];
			int front = i+1;
			int back = sz-1;
			
			// find: nums[front] + nums[back] == sum
			while(front < back) {
				int sum = nums[front] + nums[back];
				if(sum < target) front++;
				else if(sum > target) back--;
				else {
					vector<int> t(3, 0);
					t[0] = nums[i];
					t[1] = nums[front];
					t[2] = nums[back];
					
					result.push_back(t);
					
					// for duplicate Number 2, 3.
					while(front < back && nums[front] == t[1]) front++;
					while(front < back && nums[back] == t[2]) back--;
				}
			}
			
			// for duplicate Number 1.
			while(i+1 < sz && nums[i+1] == nums[i]) i++;
        }
        return result;
    }
};

#endif

int main()
{
	vector<int> nums; // {-1, 0, 1, 2, -1, -4};
	
	int n;
	while(cin >> n) {
		nums.push_back(n);
	}
	
	auto sums = Solution().threeSum(nums);
	
	for(auto v : sums){
		cout << "{";
		for(int i: v) cout << i << ",";
		cout << "}\n";
	}
	return 0;
}
