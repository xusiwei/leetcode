/*
copyright xu(xusiwei1236@163.com), all right reserved.

3Sum
======

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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        std::sort(nums.begin(), nums.end());
        for(int i = 0, sz = nums.size(); i < sz-1; ++i) {
            int a = nums[i];
            int front = i+1;
            int back = sz-1;
            
            // find: nums[front] + nums[back] == sum
            while(front < back) {
                int b = nums[front];
                int c = nums[back];
                int sum = a + b + c;
                if(sum == 0){
                    result.push_back({a, b, c});
                    
                    // for duplicate Number 2, 3.
                    while(front < back && nums[front+1] == nums[front]) front++;
                    while(front < back && nums[back-1] == nums[back]) back--;
                    front++;
                    back--;
                }
                else if(sum < 0) {
                    while(front < back && nums[front+1] == nums[front]) front++;
                    front++;
                }
                else { // if(sum > 0)
                    while(front < back && nums[back-1] == nums[back]) back--;
                    back--;
                }
            }
            
            // for duplicate Number 1.
            while(i+1 < sz && nums[i+1] == nums[i]) i++;
        }
        return result;
    }
};

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
