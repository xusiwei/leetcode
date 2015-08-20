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

#include <stdio.h>
#include <map>
#include <tuple>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

#ifdef DEBUG
#define trace printf
#else
#define trace
#endif

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums, int target) {
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
                if(sum == target){
                    result.push_back({a, b, c});
                    
                    // for duplicate Number 2, 3.
                    while(front < back && nums[front+1] == nums[front]) front++;
                    while(front < back && nums[back-1] == nums[back]) back--;
                    front++;
                    back--;
                }
                else if(sum < target) {
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
        
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        
        sort(nums.begin(), nums.end());
        for(int i = 0, sz = nums.size(); i < sz-3; ++i) {
            if (i>0 && nums[i-1] == nums[i]) continue;
            vector<int> rest(nums.begin()+i+1, nums.end());
            auto mat = threeSum(rest, target-nums[i]);
            for(int j = 0, nm = mat.size(); j < nm; j++) {
                mat[j].insert(mat[j].begin(), nums[i]);
                  result.push_back(mat[j]);
            }
        }
        
        return result;
    }
};


template<typename Vector>
void printVector(Vector v)
{
    cout << "[";
    for(int i = 0, sz = v.size(); i < sz; i++) {
        cout << v[i] << (i+1 == sz ? "]\n" : ",");
    }
}

int main()
{
    int target, n;
    vector<int> nums;
    
    cin >> target;
    while(cin >> n) {
        nums.push_back(n);
    }
    
    cout << "nums: ";
    printVector(nums);
    cout << "target:" << target << "\n\n";
    
    auto result = Solution().fourSum(nums, target);
    for(auto v: result) { cout << v[0] + v[1] + v[2] + v[3] << ": "; printVector(v); }
    return 0;
}
