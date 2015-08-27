/*
copyright xu(xusiwei1236@163.com), all right reserved.

Permutations
=============

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
class Solution {
public:

    bool nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return false;
        
        for(int i = size-1; i >= 1; --i) {
            if(nums[i-1] < nums[i]) {
                int j = size;
                while(!(nums[i-1] < nums[--j])) ;
                swap(nums[i-1], nums[j]);
                reverse(nums.begin() + i, nums.end());
                return true;
            }
        }
        reverse(nums.begin(), nums.end());
        return false;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        }while(nextPermutation(nums));
        return result;
    }
};
